/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int_53b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__int_53c_bad_sink(int * data);

void CWE476_NULL_Pointer_Dereference__int_53b_bad_sink(int * data)
{
    CWE476_NULL_Pointer_Dereference__int_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE476_NULL_Pointer_Dereference__int_53c_goodG2B_sink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__int_53b_goodG2B_sink(int * data)
{
    CWE476_NULL_Pointer_Dereference__int_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
