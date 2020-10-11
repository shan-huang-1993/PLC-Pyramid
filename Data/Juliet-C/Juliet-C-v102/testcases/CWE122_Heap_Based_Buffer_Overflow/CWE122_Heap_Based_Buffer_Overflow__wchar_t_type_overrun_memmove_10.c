/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_10.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Sinks: type_overrun_memmove
 *    GoodSink: Perform the memmove() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memmove()
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#define SRC_STR L"0123456789abcde0123"

typedef struct _charvoid
{
    wchar_t x[16];
    void * y;
    void * z;
} charvoid;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_10_bad()
{
    if(global_t)
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_f) instead of if(global_t) */
static void good1()
{
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
    else
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_t)
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printWLine((wchar_t *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct->x);
            printWLine((wchar_t *)cv_struct->y);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_10_good()
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
    CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
