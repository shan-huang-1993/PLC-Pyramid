/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_long_long_52b.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE416_Use_After_Free__malloc_free_long_long_52c_bad_sink(long long * data);

void CWE416_Use_After_Free__malloc_free_long_long_52b_bad_sink(long long * data)
{
    CWE416_Use_After_Free__malloc_free_long_long_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE416_Use_After_Free__malloc_free_long_long_52c_goodG2B_sink(long long * data);

void CWE416_Use_After_Free__malloc_free_long_long_52b_goodG2B_sink(long long * data)
{
    CWE416_Use_After_Free__malloc_free_long_long_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE416_Use_After_Free__malloc_free_long_long_52c_goodB2G_sink(long long * data);

void CWE416_Use_After_Free__malloc_free_long_long_52b_goodB2G_sink(long long * data)
{
    CWE416_Use_After_Free__malloc_free_long_long_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
