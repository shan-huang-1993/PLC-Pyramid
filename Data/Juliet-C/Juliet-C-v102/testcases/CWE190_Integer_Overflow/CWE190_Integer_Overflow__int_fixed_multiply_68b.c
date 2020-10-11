/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fixed_multiply_68b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE190_Integer_Overflow__int_fixed_multiply_68_bad_data;
extern int CWE190_Integer_Overflow__int_fixed_multiply_68_goodG2B_data;
extern int CWE190_Integer_Overflow__int_fixed_multiply_68_goodB2G_data;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fixed_multiply_68b_bad_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_multiply_68_bad_data;
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fixed_multiply_68b_goodG2B_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_multiply_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fixed_multiply_68b_goodB2G_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_multiply_68_goodB2G_data;
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
