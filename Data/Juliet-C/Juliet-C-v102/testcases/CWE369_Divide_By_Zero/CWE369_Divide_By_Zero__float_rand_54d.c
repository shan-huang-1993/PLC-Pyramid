/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_rand_54d.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__float_rand_54e_bad_sink(float data);

void CWE369_Divide_By_Zero__float_rand_54d_bad_sink(float data)
{
    CWE369_Divide_By_Zero__float_rand_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__float_rand_54e_goodG2B_sink(float data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__float_rand_54d_goodG2B_sink(float data)
{
    CWE369_Divide_By_Zero__float_rand_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
