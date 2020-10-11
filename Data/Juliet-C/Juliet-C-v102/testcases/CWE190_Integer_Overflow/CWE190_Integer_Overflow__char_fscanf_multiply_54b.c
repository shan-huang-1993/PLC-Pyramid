/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_multiply_54b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_fscanf_multiply_54c_bad_sink(char data);

void CWE190_Integer_Overflow__char_fscanf_multiply_54b_bad_sink(char data)
{
    CWE190_Integer_Overflow__char_fscanf_multiply_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fscanf_multiply_54c_goodG2B_sink(char data);

void CWE190_Integer_Overflow__char_fscanf_multiply_54b_goodG2B_sink(char data)
{
    CWE190_Integer_Overflow__char_fscanf_multiply_54c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fscanf_multiply_54c_goodB2G_sink(char data);

void CWE190_Integer_Overflow__char_fscanf_multiply_54b_goodB2G_sink(char data)
{
    CWE190_Integer_Overflow__char_fscanf_multiply_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
