/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_calloc_61b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
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

struct _twoints * CWE401_Memory_Leak__struct_twoints_calloc_61b_bad_source(struct _twoints * data)
{

    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));

    /* Initialize and make use of data */

    data[0].a = 0;
    data[0].b = 0;

    printStructLine((twoints *)&data[0]);

    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
struct _twoints * CWE401_Memory_Leak__struct_twoints_calloc_61b_goodG2B_source(struct _twoints * data)
{

    {
        /* FIX: Use memory allocated on the stack */
        struct _twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
    }

    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
struct _twoints * CWE401_Memory_Leak__struct_twoints_calloc_61b_goodB2G_source(struct _twoints * data)
{

    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));

    /* Initialize and make use of data */

    data[0].a = 0;
    data[0].b = 0;

    printStructLine((twoints *)&data[0]);

    return data;
}

#endif /* OMITGOOD */
