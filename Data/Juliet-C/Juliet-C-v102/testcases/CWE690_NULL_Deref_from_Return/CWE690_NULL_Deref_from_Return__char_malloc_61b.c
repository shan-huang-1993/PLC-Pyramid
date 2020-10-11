/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__char_malloc_61b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

char * CWE690_NULL_Deref_from_Return__char_malloc_61b_bad_source(char * data)
{
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)malloc(100);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
char * CWE690_NULL_Deref_from_Return__char_malloc_61b_goodB2G_source(char * data)
{
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)malloc(100);
    return data;
}

#endif /* OMITGOOD */
