/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_ncpy_08.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-08.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE127_Buffer_Underread__malloc_char_ncpy_08_bad()
{
    char * data;
    data = NULL;
    if(static_returns_t())
    {
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    else
    {
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(static_returns_t())
    {
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data_buf = (char *)malloc(100*sizeof(char));
            memset(data_buf, 'A', 100-1);
            data_buf[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strncpy(dest, data, strlen(dest));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

void CWE127_Buffer_Underread__malloc_char_ncpy_08_good()
{
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
    CWE127_Buffer_Underread__malloc_char_ncpy_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__malloc_char_ncpy_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif