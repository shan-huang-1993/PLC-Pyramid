/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fixed_add_61b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE190_Integer_Overflow__int_fixed_add_61b_bad_source(int data)
{
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE190_Integer_Overflow__int_fixed_add_61b_goodG2B_source(int data)
{
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE190_Integer_Overflow__int_fixed_add_61b_goodB2G_source(int data)
{
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    return data;
}

#endif /* OMITGOOD */
