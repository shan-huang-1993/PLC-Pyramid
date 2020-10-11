/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fgets_add_54d.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int_fgets_add_54e_bad_sink(int data);

void CWE190_Integer_Overflow__int_fgets_add_54d_bad_sink(int data)
{
    CWE190_Integer_Overflow__int_fgets_add_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fgets_add_54e_goodG2B_sink(int data);

void CWE190_Integer_Overflow__int_fgets_add_54d_goodG2B_sink(int data)
{
    CWE190_Integer_Overflow__int_fgets_add_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fgets_add_54e_goodB2G_sink(int data);

void CWE190_Integer_Overflow__int_fgets_add_54d_goodB2G_sink(int data)
{
    CWE190_Integer_Overflow__int_fgets_add_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
