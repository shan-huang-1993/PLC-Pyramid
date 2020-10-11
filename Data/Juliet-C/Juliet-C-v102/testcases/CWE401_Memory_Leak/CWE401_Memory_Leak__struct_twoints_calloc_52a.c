/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_calloc_52a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__struct_twoints_calloc_52b_bad_sink(struct _twoints * data);

void CWE401_Memory_Leak__struct_twoints_calloc_52_bad()
{
    struct _twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    CWE401_Memory_Leak__struct_twoints_calloc_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__struct_twoints_calloc_52b_goodG2B_sink(struct _twoints * data);

static void goodG2B()
{
    struct _twoints * data;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        struct _twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
    }
    CWE401_Memory_Leak__struct_twoints_calloc_52b_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__struct_twoints_calloc_52b_goodB2G_sink(struct _twoints * data);

static void goodB2G()
{
    struct _twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    CWE401_Memory_Leak__struct_twoints_calloc_52b_goodB2G_sink(data);
}

void CWE401_Memory_Leak__struct_twoints_calloc_52_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE401_Memory_Leak__struct_twoints_calloc_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoints_calloc_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif