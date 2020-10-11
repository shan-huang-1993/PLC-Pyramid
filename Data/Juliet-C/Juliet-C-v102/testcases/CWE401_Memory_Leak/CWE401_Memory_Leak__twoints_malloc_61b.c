/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoints_malloc_61b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
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

twoints * CWE401_Memory_Leak__twoints_malloc_61b_bad_source(twoints * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoints *)malloc(100*sizeof(twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twoints * CWE401_Memory_Leak__twoints_malloc_61b_goodG2B_source(twoints * data)
{
    {
        /* FIX: Use memory allocated on the stack */
        twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine(&data[0]);
    }
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
twoints * CWE401_Memory_Leak__twoints_malloc_61b_goodB2G_source(twoints * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoints *)malloc(100*sizeof(twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    return data;
}

#endif /* OMITGOOD */
