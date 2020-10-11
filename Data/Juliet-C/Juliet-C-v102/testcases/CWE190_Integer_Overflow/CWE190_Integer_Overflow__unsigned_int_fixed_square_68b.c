/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fixed_square_68b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

extern unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_square_68_bad_data;
extern unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_square_68_goodG2B_data;
extern unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_square_68_goodB2G_data;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fixed_square_68b_bad_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fixed_square_68_bad_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_fixed_square_68b_goodG2B_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fixed_square_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_fixed_square_68b_goodB2G_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fixed_square_68_goodB2G_data;
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
