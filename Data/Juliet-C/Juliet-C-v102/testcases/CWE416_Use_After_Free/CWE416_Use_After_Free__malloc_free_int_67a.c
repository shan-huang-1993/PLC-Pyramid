/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_int_67a.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE416_Use_After_Free__malloc_free_int_67_struct_type
{
    int * a;
} CWE416_Use_After_Free__malloc_free_int_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE416_Use_After_Free__malloc_free_int_67b_bad_sink(CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct);

void CWE416_Use_After_Free__malloc_free_int_67_bad()
{
    int * data;
    CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    my_struct.a = data;
    CWE416_Use_After_Free__malloc_free_int_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE416_Use_After_Free__malloc_free_int_67b_goodG2B_sink(CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct);

static void goodG2B()
{
    int * data;
    CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    /* FIX: Do not delete data in the source */
    my_struct.a = data;
    CWE416_Use_After_Free__malloc_free_int_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE416_Use_After_Free__malloc_free_int_67b_goodB2G_sink(CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct);

static void goodB2G()
{
    int * data;
    CWE416_Use_After_Free__malloc_free_int_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    my_struct.a = data;
    CWE416_Use_After_Free__malloc_free_int_67b_goodB2G_sink(my_struct);
}

void CWE416_Use_After_Free__malloc_free_int_67_good()
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
    CWE416_Use_After_Free__malloc_free_int_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
