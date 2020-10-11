/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_16.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_16_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* FIX: Do not delete data in the source */
        break;
    }
    while(1)
    {
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* FIX: Do not delete data in the source */
        break;
    }
    while(1)
    {
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(1)
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* FIX: Do not delete data in the source */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].a = 1;
                data[i].b = 2;
            }
        }
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

void CWE416_Use_After_Free__malloc_free_struct_16_good()
{
    goodB2G();
    goodG2B();
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
    CWE416_Use_After_Free__malloc_free_struct_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
