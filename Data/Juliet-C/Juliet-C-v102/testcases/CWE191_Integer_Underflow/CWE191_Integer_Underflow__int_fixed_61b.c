/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fixed_61b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE191_Integer_Underflow__int_fixed_61b_bad_source(int data)
{
    /* FLAW: Use the minimum size of the data type */
    data = INT_MIN;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE191_Integer_Underflow__int_fixed_61b_goodG2B_source(int data)
{
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE191_Integer_Underflow__int_fixed_61b_goodB2G_source(int data)
{
    /* FLAW: Use the minimum size of the data type */
    data = INT_MIN;
    return data;
}

#endif /* OMITGOOD */
