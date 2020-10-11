/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_fixed_68b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern unsigned int CWE191_Integer_Underflow__unsigned_int_fixed_68_bad_data;
extern unsigned int CWE191_Integer_Underflow__unsigned_int_fixed_68_goodG2B_data;
extern unsigned int CWE191_Integer_Underflow__unsigned_int_fixed_68_goodB2G_data;

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_int_fixed_68b_bad_sink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_fixed_68_bad_data;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_int_fixed_68b_goodG2B_sink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_fixed_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_int_fixed_68b_goodB2G_sink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_fixed_68_goodB2G_data;
    {
        unsigned int result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > 0)
        {
            result = data - 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
