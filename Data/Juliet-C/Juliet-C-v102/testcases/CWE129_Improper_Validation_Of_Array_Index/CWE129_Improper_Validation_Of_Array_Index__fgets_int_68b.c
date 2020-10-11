/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__fgets_int_68b.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

extern int CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_bad_data;
extern int CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_goodG2B_data;
extern int CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_goodB2G_data;

#ifndef OMITBAD

void CWE129_Improper_Validation_Of_Array_Index__fgets_int_68b_bad_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_bad_data;
    {
        int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__fgets_int_68b_goodG2B_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_goodG2B_data;
    {
        int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__fgets_int_68b_goodB2G_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__fgets_int_68_goodB2G_data;
    {
        int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
        /* FIX: Properly validate the array index */
        if (data >= 0 && data < 10)
        {
            printIntLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

#endif /* OMITGOOD */
