/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_64b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fgets_for_loop_64b_bad_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_64b_goodG2B_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_64b_goodB2G_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
    {
        size_t i = 0;
        /* FIX: Validate $Data% before using it as the for loop variant */
        if (count > 0 && count <= 20)
        {
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

#endif /* OMITGOOD */
