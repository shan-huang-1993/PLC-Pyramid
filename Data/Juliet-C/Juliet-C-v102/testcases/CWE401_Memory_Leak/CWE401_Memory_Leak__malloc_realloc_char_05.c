/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_char_05.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_char_05_bad()
{
    if(static_t)
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (char *)realloc(data, (130000)*sizeof(char));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
                free(data);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = (char *)malloc(100*sizeof(char));
            char * tmp;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            tmp = (char *)realloc(data, (130000)*sizeof(char));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
            }
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = (char *)malloc(100*sizeof(char));
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (char *)realloc(data, (130000)*sizeof(char));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
                free(data);
            }
        }
    }
    else
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            char * tmp;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            tmp = (char *)realloc(data, (130000)*sizeof(char));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
            }
            free(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            char * tmp;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            tmp = (char *)realloc(data, (130000)*sizeof(char));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
            }
            free(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = (char *)malloc(100*sizeof(char));
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (char *)realloc(data, (130000)*sizeof(char));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                strcpy(data, "New String");
                printLine(data);
                free(data);
            }
        }
    }
}

void CWE401_Memory_Leak__malloc_realloc_char_05_good()
{
    good1();
    good2();
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
    CWE401_Memory_Leak__malloc_realloc_char_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_char_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
