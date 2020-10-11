/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__struct_calloc_54c.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__struct_calloc_54d_bad_sink(twoints * data);

void CWE690_NULL_Deref_from_Return__struct_calloc_54c_bad_sink(twoints * data)
{
    CWE690_NULL_Deref_from_Return__struct_calloc_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__struct_calloc_54d_goodB2G_sink(twoints * data);

void CWE690_NULL_Deref_from_Return__struct_calloc_54c_goodB2G_sink(twoints * data)
{
    CWE690_NULL_Deref_from_Return__struct_calloc_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
