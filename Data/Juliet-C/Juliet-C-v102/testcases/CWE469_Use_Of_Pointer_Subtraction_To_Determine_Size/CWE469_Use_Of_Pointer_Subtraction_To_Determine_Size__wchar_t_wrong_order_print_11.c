/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_wrong_order_print_11.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: wrong_order_print
 *    GoodSink: Subtract pointers correctly and print data
 *    BadSink : Beginning and end pointers are switched leading to an incorrect index when printing
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_wrong_order_print_11_bad()
{
    if(global_returns_t())
    {
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FLAW: switched the beginning and end pointers around, leads to incorrect index when
             * printing
             */
            indexOfSlash = (size_t)(string - slash);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FIX: subtract pointers in the correct order ('slash - string') */
            indexOfSlash = (size_t)(slash - string);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FLAW: switched the beginning and end pointers around, leads to incorrect index when
             * printing
             */
            indexOfSlash = (size_t)(string - slash);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
    else
    {
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FIX: subtract pointers in the correct order ('slash - string') */
            indexOfSlash = (size_t)(slash - string);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_returns_t())
    {
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FIX: subtract pointers in the correct order ('slash - string') */
            indexOfSlash = (size_t)(slash - string);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data;
            wchar_t string[] = SRC_STR;
            wchar_t * slash;
            size_t indexOfSlash;
            slash = wcschr(string, L'/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FLAW: switched the beginning and end pointers around, leads to incorrect index when
             * printing
             */
            indexOfSlash = (size_t)(string - slash);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printWLine(data);
        }
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_wrong_order_print_11_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_wrong_order_print_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_wrong_order_print_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
