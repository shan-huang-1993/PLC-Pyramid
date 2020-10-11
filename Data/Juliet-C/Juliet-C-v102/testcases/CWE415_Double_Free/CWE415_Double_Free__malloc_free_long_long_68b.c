/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_long_68b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern long long * CWE415_Double_Free__malloc_free_long_long_68_bad_data;
extern long long * CWE415_Double_Free__malloc_free_long_long_68_goodG2B_data;
extern long long * CWE415_Double_Free__malloc_free_long_long_68_goodB2G_data;

#ifndef OMITBAD

void CWE415_Double_Free__malloc_free_long_long_68b_bad_sink()
{
    long long * data = CWE415_Double_Free__malloc_free_long_long_68_bad_data;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_long_long_68b_goodG2B_sink()
{
    long long * data = CWE415_Double_Free__malloc_free_long_long_68_goodG2B_data;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_long_long_68b_goodB2G_sink()
{
    long long * data = CWE415_Double_Free__malloc_free_long_long_68_goodB2G_data;
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */
