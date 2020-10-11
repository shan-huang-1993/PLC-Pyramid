/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_realloc_66b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__struct_twoints_realloc_66b_bad_sink(struct _twoints * data_array[])
{
    /* copy data out of data_array */
    struct _twoints * data = data_array[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__struct_twoints_realloc_66b_goodG2B_sink(struct _twoints * data_array[])
{
    struct _twoints * data = data_array[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__struct_twoints_realloc_66b_goodB2G_sink(struct _twoints * data_array[])
{
    struct _twoints * data = data_array[2];
    /* FIX: Deallocate memory */
    free(data);
}

#endif /* OMITGOOD */
