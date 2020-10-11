/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_square_54c.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_rand_square_54d_bad_sink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_square_54c_bad_sink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_rand_square_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_rand_square_54d_goodG2B_sink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_square_54c_goodG2B_sink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_rand_square_54d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_rand_square_54d_goodB2G_sink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_square_54c_goodB2G_sink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_rand_square_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
