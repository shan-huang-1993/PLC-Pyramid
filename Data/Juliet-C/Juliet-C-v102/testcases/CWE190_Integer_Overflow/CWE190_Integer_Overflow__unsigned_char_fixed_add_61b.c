/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fixed_add_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
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

unsigned char CWE190_Integer_Overflow__unsigned_char_fixed_add_61b_bad_source(unsigned char data)
{
    /* FLAW: Use the maximum size of the data type */
    data = UCHAR_MAX;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
unsigned char CWE190_Integer_Overflow__unsigned_char_fixed_add_61b_goodG2B_source(unsigned char data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
unsigned char CWE190_Integer_Overflow__unsigned_char_fixed_add_61b_goodB2G_source(unsigned char data)
{
    /* FLAW: Use the maximum size of the data type */
    data = UCHAR_MAX;
    return data;
}

#endif /* OMITGOOD */
