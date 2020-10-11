/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fgets_square_68b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the square root
 *    BadSink : Square data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#include <math.h>

extern int CWE190_Integer_Overflow__int_fgets_square_68_bad_data;
extern int CWE190_Integer_Overflow__int_fgets_square_68_goodG2B_data;
extern int CWE190_Integer_Overflow__int_fgets_square_68_goodB2G_data;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fgets_square_68b_bad_sink()
{
    int data = CWE190_Integer_Overflow__int_fgets_square_68_bad_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fgets_square_68b_goodG2B_sink()
{
    int data = CWE190_Integer_Overflow__int_fgets_square_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fgets_square_68b_goodB2G_sink()
{
    int data = CWE190_Integer_Overflow__int_fgets_square_68_goodB2G_data;
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (int)sqrt((int)INT_MAX))
        {
            result = data * data;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
