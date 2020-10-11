/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_int_53c.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE416_Use_After_Free__malloc_free_int_53d_bad_sink(int * data);

void CWE416_Use_After_Free__malloc_free_int_53c_bad_sink(int * data)
{
    CWE416_Use_After_Free__malloc_free_int_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE416_Use_After_Free__malloc_free_int_53d_goodG2B_sink(int * data);

void CWE416_Use_After_Free__malloc_free_int_53c_goodG2B_sink(int * data)
{
    CWE416_Use_After_Free__malloc_free_int_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE416_Use_After_Free__malloc_free_int_53d_goodB2G_sink(int * data);

void CWE416_Use_After_Free__malloc_free_int_53c_goodB2G_sink(int * data)
{
    CWE416_Use_After_Free__malloc_free_int_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
