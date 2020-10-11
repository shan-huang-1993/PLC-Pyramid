/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_54d.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__struct_54e_bad_sink(twoints * data);

void CWE476_NULL_Pointer_Dereference__struct_54d_bad_sink(twoints * data)
{
    CWE476_NULL_Pointer_Dereference__struct_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE476_NULL_Pointer_Dereference__struct_54e_goodG2B_sink(twoints * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__struct_54d_goodG2B_sink(twoints * data)
{
    CWE476_NULL_Pointer_Dereference__struct_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
