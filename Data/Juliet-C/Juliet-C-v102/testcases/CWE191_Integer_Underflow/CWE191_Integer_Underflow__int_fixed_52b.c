/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fixed_52b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__int_fixed_52c_bad_sink(int data);

void CWE191_Integer_Underflow__int_fixed_52b_bad_sink(int data)
{
    CWE191_Integer_Underflow__int_fixed_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_fixed_52c_goodG2B_sink(int data);

void CWE191_Integer_Underflow__int_fixed_52b_goodG2B_sink(int data)
{
    CWE191_Integer_Underflow__int_fixed_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_fixed_52c_goodB2G_sink(int data);

void CWE191_Integer_Underflow__int_fixed_52b_goodB2G_sink(int data)
{
    CWE191_Integer_Underflow__int_fixed_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
