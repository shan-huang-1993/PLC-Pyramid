/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__long_long_realloc_67a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__long_long_realloc_67_struct_type
{
    long long * a;
} CWE401_Memory_Leak__long_long_realloc_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__long_long_realloc_67b_bad_sink(CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct);

void CWE401_Memory_Leak__long_long_realloc_67_bad()
{
    long long * data;
    CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    my_struct.a = data;
    CWE401_Memory_Leak__long_long_realloc_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__long_long_realloc_67b_goodG2B_sink(CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct);

static void goodG2B()
{
    long long * data;
    CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        long long data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0] = 5L;
        printLongLongLine(data[0]);
    }
    my_struct.a = data;
    CWE401_Memory_Leak__long_long_realloc_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__long_long_realloc_67b_goodB2G_sink(CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct);

static void goodB2G()
{
    long long * data;
    CWE401_Memory_Leak__long_long_realloc_67_struct_type my_struct;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    my_struct.a = data;
    CWE401_Memory_Leak__long_long_realloc_67b_goodB2G_sink(my_struct);
}

void CWE401_Memory_Leak__long_long_realloc_67_good()
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
    CWE401_Memory_Leak__long_long_realloc_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__long_long_realloc_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
