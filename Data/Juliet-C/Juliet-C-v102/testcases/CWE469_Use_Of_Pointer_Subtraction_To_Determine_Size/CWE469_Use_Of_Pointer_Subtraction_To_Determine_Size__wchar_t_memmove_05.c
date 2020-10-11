/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_05.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: memmove
 *    GoodSink: using correct pointer subtraction to determine length in memmove()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in memmove()
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_05_bad()
{
    if(static_t)
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
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
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
    else
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_05_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
