/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_divide_54b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fscanf_divide_54c_bad_sink(int data);

void CWE369_Divide_By_Zero__int_fscanf_divide_54b_bad_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_divide_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_fscanf_divide_54c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fscanf_divide_54b_goodG2B_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_divide_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
