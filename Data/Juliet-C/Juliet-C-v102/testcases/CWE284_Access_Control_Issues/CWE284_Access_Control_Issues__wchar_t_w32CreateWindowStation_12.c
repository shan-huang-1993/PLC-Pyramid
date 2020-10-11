/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__wchar_t_w32CreateWindowStation_12.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationW() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationW() with excessive privileges
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Access_Control_Issues__wchar_t_w32CreateWindowStation_12_bad()
{
    if(global_returns_t_or_f())
    {
#ifdef _WIN32
        {
            HWINSTA hWStation;
            wchar_t * wStationName = L"WindowsStationExample";

            /* FLAW: Call CreateWindowStationW() with GENERIC_ALL as the 3rd parameter */
            hWStation = CreateWindowStationW(
                wStationName,
                0,
                GENERIC_ALL,
                NULL);

            if (hWStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
    else
    {
#ifdef _WIN32
        {
            HWINSTA hWStation;
            wchar_t * wStationName = L"WindowsStationExample";

            /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
            hWStation = CreateWindowStationW(
                wStationName,
                0,
                GENERIC_READ,
                NULL);

            if (hWStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
#ifdef _WIN32
        {
            HWINSTA hWStation;
            wchar_t * wStationName = L"WindowsStationExample";

            /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
            hWStation = CreateWindowStationW(
                wStationName,
                0,
                GENERIC_READ,
                NULL);

            if (hWStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
    else
    {
#ifdef _WIN32
        {
            HWINSTA hWStation;
            wchar_t * wStationName = L"WindowsStationExample";

            /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
            hWStation = CreateWindowStationW(
                wStationName,
                0,
                GENERIC_READ,
                NULL);

            if (hWStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
}

void CWE284_Access_Control_Issues__wchar_t_w32CreateWindowStation_12_good()
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
    CWE284_Access_Control_Issues__wchar_t_w32CreateWindowStation_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__wchar_t_w32CreateWindowStation_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
