/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_68b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE400_Resource_Exhaustion__rand_for_loop_68_bad_data;
extern int CWE400_Resource_Exhaustion__rand_for_loop_68_goodG2B_data;
extern int CWE400_Resource_Exhaustion__rand_for_loop_68_goodB2G_data;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_for_loop_68b_bad_sink()
{
    int count = CWE400_Resource_Exhaustion__rand_for_loop_68_bad_data;
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
void CWE400_Resource_Exhaustion__rand_for_loop_68b_goodG2B_sink()
{
    int count = CWE400_Resource_Exhaustion__rand_for_loop_68_goodG2B_data;
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
void CWE400_Resource_Exhaustion__rand_for_loop_68b_goodB2G_sink()
{
    int count = CWE400_Resource_Exhaustion__rand_for_loop_68_goodB2G_data;
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
