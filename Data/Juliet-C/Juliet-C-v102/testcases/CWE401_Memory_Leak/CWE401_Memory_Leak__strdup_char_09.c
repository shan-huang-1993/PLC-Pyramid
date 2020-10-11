/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_09.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__strdup_char_09_bad()
{
    char * data;
    data = NULL;
    if(global_const_t)
    {
        {
            char mystring[] = "mystring";
            /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(mystring);
            /* Use data */
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Allocate memory from the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize then use data */
            strcpy(data, "a string");
            printLine(data);
        }
    }
    if(global_const_t)
    {
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_const_t to global_const_f */
static void goodB2G1()
{
    char * data;
    data = NULL;
    if(global_const_t)
    {
        {
            char mystring[] = "mystring";
            /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(mystring);
            /* Use data */
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Allocate memory from the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize then use data */
            strcpy(data, "a string");
            printLine(data);
        }
    }
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory initialized in the source */
        free(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    data = NULL;
    if(global_const_t)
    {
        {
            char mystring[] = "mystring";
            /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(mystring);
            /* Use data */
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Allocate memory from the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize then use data */
            strcpy(data, "a string");
            printLine(data);
        }
    }
    if(global_const_t)
    {
        /* FIX: Deallocate memory initialized in the source */
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_const_t to global_const_f */
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char mystring[] = "mystring";
            /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(mystring);
            /* Use data */
            printLine(data);
        }
    }
    else
    {
        {
            /* FIX: Allocate memory from the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize then use data */
            strcpy(data, "a string");
            printLine(data);
        }
    }
    if(global_const_t)
    {
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(global_const_t)
    {
        {
            /* FIX: Allocate memory from the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize then use data */
            strcpy(data, "a string");
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char mystring[] = "mystring";
            /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
            data = strdup(mystring);
            /* Use data */
            printLine(data);
        }
    }
    if(global_const_t)
    {
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
    }
}

void CWE401_Memory_Leak__strdup_char_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE401_Memory_Leak__strdup_char_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_char_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
