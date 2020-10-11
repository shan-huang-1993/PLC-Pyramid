/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_add_53b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int_rand_add_53c_bad_sink(int data);

void CWE190_Integer_Overflow__int_rand_add_53b_bad_sink(int data)
{
    CWE190_Integer_Overflow__int_rand_add_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_rand_add_53c_goodG2B_sink(int data);

void CWE190_Integer_Overflow__int_rand_add_53b_goodG2B_sink(int data)
{
    CWE190_Integer_Overflow__int_rand_add_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_rand_add_53c_goodB2G_sink(int data);

void CWE190_Integer_Overflow__int_rand_add_53b_goodB2G_sink(int data)
{
    CWE190_Integer_Overflow__int_rand_add_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
