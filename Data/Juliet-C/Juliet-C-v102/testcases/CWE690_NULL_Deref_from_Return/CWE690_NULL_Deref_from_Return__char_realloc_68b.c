/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__char_realloc_68b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_bad_sink;

extern char * CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_good_sink;

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__char_realloc_68b_bad_sink()
{
    char * data = CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_bad_sink;
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    strcpy(data, "Initialize");
    printLine(data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE690_NULL_Deref_from_Return__char_realloc_68b_goodB2G_sink()
{
    char * data = CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_good_sink;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        strcpy(data, "Initialize");
        printLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
