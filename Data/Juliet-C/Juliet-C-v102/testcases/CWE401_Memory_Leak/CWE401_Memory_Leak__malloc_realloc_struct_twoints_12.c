/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_struct_twoints_12.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_struct_twoints_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            struct _twoints * data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (struct _twoints *)realloc(data, (130000)*sizeof(struct _twoints));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0].a = 1;
                data[0].b = 1;
                printStructLine((twoints *)&data[0]);
                free(data);
            }
        }
    }
    else
    {
        {
            struct _twoints * data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
            struct _twoints * tmp;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
            tmp = (struct _twoints *)realloc(data, (130000)*sizeof(struct _twoints));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0].a = 1;
                data[0].b = 1;
                printStructLine((twoints *)&data[0]);
            }
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            struct _twoints * data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
            struct _twoints * tmp;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
            tmp = (struct _twoints *)realloc(data, (130000)*sizeof(struct _twoints));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0].a = 1;
                data[0].b = 1;
                printStructLine((twoints *)&data[0]);
            }
            free(data);
        }
    }
    else
    {
        {
            struct _twoints * data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
            struct _twoints * tmp;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
            tmp = (struct _twoints *)realloc(data, (130000)*sizeof(struct _twoints));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0].a = 1;
                data[0].b = 1;
                printStructLine((twoints *)&data[0]);
            }
            free(data);
        }
    }
}

void CWE401_Memory_Leak__malloc_realloc_struct_twoints_12_good()
{
    good1();
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
    CWE401_Memory_Leak__malloc_realloc_struct_twoints_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_struct_twoints_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
