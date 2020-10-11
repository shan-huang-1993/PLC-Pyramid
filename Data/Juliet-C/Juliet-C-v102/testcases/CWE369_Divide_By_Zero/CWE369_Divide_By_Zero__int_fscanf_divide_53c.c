/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_divide_53c.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fscanf_divide_53d_bad_sink(int data);

void CWE369_Divide_By_Zero__int_fscanf_divide_53c_bad_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_divide_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_fscanf_divide_53d_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fscanf_divide_53c_goodG2B_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_divide_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
