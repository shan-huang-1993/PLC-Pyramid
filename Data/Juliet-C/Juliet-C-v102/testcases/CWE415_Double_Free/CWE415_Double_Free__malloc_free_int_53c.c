/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_53c.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_int_53d_bad_sink(int * data);

void CWE415_Double_Free__malloc_free_int_53c_bad_sink(int * data)
{
    CWE415_Double_Free__malloc_free_int_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_int_53d_goodG2B_sink(int * data);

void CWE415_Double_Free__malloc_free_int_53c_goodG2B_sink(int * data)
{
    CWE415_Double_Free__malloc_free_int_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_int_53d_goodB2G_sink(int * data);

void CWE415_Double_Free__malloc_free_int_53c_goodB2G_sink(int * data)
{
    CWE415_Double_Free__malloc_free_int_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
