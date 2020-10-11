/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__long_long_realloc_61b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

long long * CWE401_Memory_Leak__long_long_realloc_61b_bad_source(long long * data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
long long * CWE401_Memory_Leak__long_long_realloc_61b_goodG2B_source(long long * data)
{
    {
        /* FIX: Use memory allocated on the stack */
        long long data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0] = 5L;
        printLongLongLine(data[0]);
    }
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
long long * CWE401_Memory_Leak__long_long_realloc_61b_goodB2G_source(long long * data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    return data;
}

#endif /* OMITGOOD */
