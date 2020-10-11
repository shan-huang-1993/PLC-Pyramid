/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fixed_53b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__char_fixed_53c_bad_sink(char data);

void CWE191_Integer_Underflow__char_fixed_53b_bad_sink(char data)
{
    CWE191_Integer_Underflow__char_fixed_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__char_fixed_53c_goodG2B_sink(char data);

void CWE191_Integer_Underflow__char_fixed_53b_goodG2B_sink(char data)
{
    CWE191_Integer_Underflow__char_fixed_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__char_fixed_53c_goodB2G_sink(char data);

void CWE191_Integer_Underflow__char_fixed_53b_goodB2G_sink(char data)
{
    CWE191_Integer_Underflow__char_fixed_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
