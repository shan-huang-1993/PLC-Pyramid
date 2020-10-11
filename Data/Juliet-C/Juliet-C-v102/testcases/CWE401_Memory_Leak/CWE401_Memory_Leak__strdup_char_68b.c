/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_68b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE401_Memory_Leak__strdup_char_68_bad_data;
extern char * CWE401_Memory_Leak__strdup_char_68_goodG2B_data;
extern char * CWE401_Memory_Leak__strdup_char_68_goodB2G_data;

#ifndef OMITBAD

void CWE401_Memory_Leak__strdup_char_68b_bad_sink()
{
    char * data = CWE401_Memory_Leak__strdup_char_68_bad_data;
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__strdup_char_68b_goodG2B_sink()
{
    char * data = CWE401_Memory_Leak__strdup_char_68_goodG2B_data;
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__strdup_char_68b_goodB2G_sink()
{
    char * data = CWE401_Memory_Leak__strdup_char_68_goodB2G_data;
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

#endif /* OMITGOOD */
