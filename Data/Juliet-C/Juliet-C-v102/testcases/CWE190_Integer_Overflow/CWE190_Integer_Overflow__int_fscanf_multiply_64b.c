/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_multiply_64b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fscanf_multiply_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * data_ptr = (int *)void_data_ptr;
    /* dereference data_ptr into data */
    int data = (*data_ptr);
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fscanf_multiply_64b_goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * data_ptr = (int *)void_data_ptr;
    /* dereference data_ptr into data */
    int data = (*data_ptr);
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fscanf_multiply_64b_goodB2G_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * data_ptr = (int *)void_data_ptr;
    /* dereference data_ptr into data */
    int data = (*data_ptr);
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (INT_MAX/2))
        {
            result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
