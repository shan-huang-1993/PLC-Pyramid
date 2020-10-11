/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32CreateDesktop_08.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateDesktop
 *    GoodSink: Create a desktop using CreateDesktopA() without excessive privileges
 *    BadSink : Create a desktop using CreateDesktopA() with excessive privileges
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

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

void CWE284_Access_Control_Issues__char_w32CreateDesktop_08_bad()
{
    if(static_returns_t())
    {
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";

            /* FLAW: Call CreateDesktopA() with GENERIC_ALL as the 5th parameter */
            hDesk = CreateDesktopA(
                dtName,
                NULL,
                NULL,
                0,
                GENERIC_ALL,
                NULL);

            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";
            /* FIX: Call CreateDesktopA() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopA(
                        dtName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_READ,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";
            /* FLAW: Call CreateDesktopA() with GENERIC_ALL as the 5th parameter */
            hDesk = CreateDesktopA(
                        dtName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_ALL,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
    else
    {
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";

            /* FIX: Call CreateDesktopA() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopA(
                dtName,
                NULL,
                NULL,
                0,
                GENERIC_READ,
                NULL);

            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";

            /* FIX: Call CreateDesktopA() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopA(
                dtName,
                NULL,
                NULL,
                0,
                GENERIC_READ,
                NULL);

            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            HDESK hDesk;
            char * dtName = "DesktopExample";
            /* FLAW: Call CreateDesktopA() with GENERIC_ALL as the 5th parameter */
            hDesk = CreateDesktopA(
                        dtName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_ALL,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
#endif
    }
}

void CWE284_Access_Control_Issues__char_w32CreateDesktop_08_good()
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
    CWE284_Access_Control_Issues__char_w32CreateDesktop_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32CreateDesktop_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
