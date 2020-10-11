/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__double_53c.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__double_53d_bad_sink(double * data);

void CWE467_Use_of_sizeof_on_Pointer_Type__double_53c_bad_sink(double * data)
{
    CWE467_Use_of_sizeof_on_Pointer_Type__double_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__double_53d_goodG2B_sink(double * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE467_Use_of_sizeof_on_Pointer_Type__double_53c_goodG2B_sink(double * data)
{
    CWE467_Use_of_sizeof_on_Pointer_Type__double_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
