/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_loop_19.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: loop
 *    GoodSink: using correct pointer subtraction to determine length in loop
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in the loop
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_loop_19_bad()
{
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        ptrdiff_t i;
        /* FLAW: switched the beginning and end pointers around */
        for (i = 0; i < (data - end); i++)
        {
            dst[i] = data[i];
        }
        printWLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        ptrdiff_t i;
        /* FIX: use proper order in pointer subtraction */
        for (i = 0; i < (end - data); i++)
        {
            dst[i] = data[i];
        }
        printWLine(dst);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        ptrdiff_t i;
        /* FIX: use proper order in pointer subtraction */
        for (i = 0; i < (end - data); i++)
        {
            dst[i] = data[i];
        }
        printWLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t * data = SRC_STR;
        wchar_t dst[100] = L"";
        wchar_t * end = wcschr(data, L'/');
        ptrdiff_t i;
        /* FLAW: switched the beginning and end pointers around */
        for (i = 0; i < (data - end); i++)
        {
            dst[i] = data[i];
        }
        printWLine(dst);
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_loop_19_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_loop_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_loop_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
