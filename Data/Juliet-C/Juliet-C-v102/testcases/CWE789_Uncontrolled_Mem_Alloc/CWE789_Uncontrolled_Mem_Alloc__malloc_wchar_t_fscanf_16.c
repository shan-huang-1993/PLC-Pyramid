/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_16.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

#ifndef OMITBAD

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_16_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    while(1)
    {
        fscanf (stdin, "%d", &data);
        break;
    }
    while(1)
    {
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    while(1)
    {
        fscanf (stdin, "%d", &data);
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
        break;
    }
    while(1)
    {
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    while(1)
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
        break;
    }
    while(1)
    {
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
        break;
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_16_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
