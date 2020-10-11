/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_16.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: memmove
 *    GoodSink: using correct pointer subtraction to determine length in memmove()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in memmove()
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_16_bad()
{
    while(1)
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
        break;
    }
    while(0)
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
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
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
        break;
    }
    while(1)
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
        break;
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_16_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
