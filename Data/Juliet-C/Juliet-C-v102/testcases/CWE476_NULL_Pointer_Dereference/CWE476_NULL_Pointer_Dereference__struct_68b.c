/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_68b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern twoints * CWE476_NULL_Pointer_Dereference__struct_68_bad_data;
extern twoints * CWE476_NULL_Pointer_Dereference__struct_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__struct_68b_bad_sink()
{
    twoints * data = CWE476_NULL_Pointer_Dereference__struct_68_bad_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printStructLine(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__struct_68b_goodG2B_sink()
{
    twoints * data = CWE476_NULL_Pointer_Dereference__struct_68_goodG2B_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printStructLine(data);
}

#endif /* OMITGOOD */
