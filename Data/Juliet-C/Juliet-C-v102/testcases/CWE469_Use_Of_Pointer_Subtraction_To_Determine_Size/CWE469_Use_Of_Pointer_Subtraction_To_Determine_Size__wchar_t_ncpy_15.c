/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_ncpy_15.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: ncpy
 *    GoodSink: using correct pointer subtraction to determine length in wcsncpy()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in wcsncpy()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_ncpy_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FLAW: switched the beginning and end pointers around */
        wcsncpy(dst, data, data - end);
        printWLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FIX: use proper order in pointer subtraction */
        wcsncpy(dst, data, end - data);
        printWLine(dst);
    }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FLAW: switched the beginning and end pointers around */
        wcsncpy(dst, data, data - end);
        printWLine(dst);
    }
    break;
    default:
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FIX: use proper order in pointer subtraction */
        wcsncpy(dst, data, end - data);
        printWLine(dst);
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FIX: use proper order in pointer subtraction */
        wcsncpy(dst, data, end - data);
        printWLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        /* FLAW: switched the beginning and end pointers around */
        wcsncpy(dst, data, data - end);
        printWLine(dst);
    }
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_ncpy_15_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_ncpy_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_ncpy_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
