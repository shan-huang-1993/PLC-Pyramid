/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__wchar_t_w32CreateMutex_05.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: w32CreateMutex
 *    GoodSink: Check the return value of CreateMutexW() and handle it properly
 *    BadSink : Check to see if CreateMutexW() failed, but do nothing about it
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#define BUFSIZE 1024

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE390_Error_Without_Action__wchar_t_w32CreateMutex_05_bad()
{
    if(static_t)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FLAW: check for an error, but do nothing if one occurred */
            if (hMutex == NULL)
            {
                /* do nothing */
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                /* do nothing */
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FIX: Check the return value of CreateMutex() for NULL AND
             * Check the return value of GetLastError() for ERROR_ALREADY_EXISTS */
            if (hMutex == NULL)
            {
                exit(1);
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
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
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FLAW: check for an error, but do nothing if one occurred */
            if (hMutex == NULL)
            {
                /* do nothing */
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                /* do nothing */
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
    }
    else
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FIX: Check the return value of CreateMutex() for NULL AND
             * Check the return value of GetLastError() for ERROR_ALREADY_EXISTS */
            if (hMutex == NULL)
            {
                exit(1);
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FIX: Check the return value of CreateMutex() for NULL AND
             * Check the return value of GetLastError() for ERROR_ALREADY_EXISTS */
            if (hMutex == NULL)
            {
                exit(1);
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FLAW: check for an error, but do nothing if one occurred */
            if (hMutex == NULL)
            {
                /* do nothing */
            }
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                /* do nothing */
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
    }
}

void CWE390_Error_Without_Action__wchar_t_w32CreateMutex_05_good()
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
    CWE390_Error_Without_Action__wchar_t_w32CreateMutex_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__wchar_t_w32CreateMutex_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
