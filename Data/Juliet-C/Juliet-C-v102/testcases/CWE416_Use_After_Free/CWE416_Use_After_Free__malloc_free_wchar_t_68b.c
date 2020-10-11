/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_wchar_t_68b.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE416_Use_After_Free__malloc_free_wchar_t_68_bad_data;
extern wchar_t * CWE416_Use_After_Free__malloc_free_wchar_t_68_goodG2B_data;
extern wchar_t * CWE416_Use_After_Free__malloc_free_wchar_t_68_goodB2G_data;

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_wchar_t_68b_bad_sink()
{
    wchar_t * data = CWE416_Use_After_Free__malloc_free_wchar_t_68_bad_data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printWLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE416_Use_After_Free__malloc_free_wchar_t_68b_goodG2B_sink()
{
    wchar_t * data = CWE416_Use_After_Free__malloc_free_wchar_t_68_goodG2B_data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printWLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE416_Use_After_Free__malloc_free_wchar_t_68b_goodB2G_sink()
{
    wchar_t * data = CWE416_Use_After_Free__malloc_free_wchar_t_68_goodB2G_data;
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */
