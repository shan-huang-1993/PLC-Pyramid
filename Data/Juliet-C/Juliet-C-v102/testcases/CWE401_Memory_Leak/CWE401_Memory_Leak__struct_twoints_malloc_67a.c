/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_malloc_67a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type
{
    struct _twoints * a;
} CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__struct_twoints_malloc_67b_bad_sink(CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct);

void CWE401_Memory_Leak__struct_twoints_malloc_67_bad()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    my_struct.a = data;
    CWE401_Memory_Leak__struct_twoints_malloc_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__struct_twoints_malloc_67b_goodG2B_sink(CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct);

static void goodG2B()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct;
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
    my_struct.a = data;
    CWE401_Memory_Leak__struct_twoints_malloc_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__struct_twoints_malloc_67b_goodB2G_sink(CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct);

static void goodB2G()
{
    struct _twoints * data;
    CWE401_Memory_Leak__struct_twoints_malloc_67_struct_type my_struct;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine((twoints *)&data[0]);
    my_struct.a = data;
    CWE401_Memory_Leak__struct_twoints_malloc_67b_goodB2G_sink(my_struct);
}

void CWE401_Memory_Leak__struct_twoints_malloc_67_good()
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
    CWE401_Memory_Leak__struct_twoints_malloc_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoints_malloc_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
