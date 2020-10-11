/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__wchar_t_w32SHRegOpenUSKey_12.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32SHRegOpenUSKey
 *    GoodSink: Open a registry key using SHRegOpenUSKeyW() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using SHRegOpenUSKeyW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__wchar_t_w32SHRegOpenUSKey_12_bad()
{
    if(global_returns_t_or_f())
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;
            HUSKEY outKey;

            /* FLAW: Call SHRegOpenUSKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegOpenUSKeyW(
                key,
                KEY_WRITE,
                &hKey,
                &outKey,
                0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else {
                printLine("Registry key opened successfully");
            }
        }
#endif
    }
    else
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            HUSKEY outKey;

            /* FIX: Call SHRegOpenUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegOpenUSKeyW(
                key,
                KEY_WRITE,
                &hKey,
                &outKey,
                0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else {
                printLine("Registry key opened successfully");
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
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            HUSKEY outKey;

            /* FIX: Call SHRegOpenUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegOpenUSKeyW(
                key,
                KEY_WRITE,
                &hKey,
                &outKey,
                0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else {
                printLine("Registry key opened successfully");
            }
        }
#endif
    }
    else
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            HUSKEY outKey;

            /* FIX: Call SHRegOpenUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegOpenUSKeyW(
                key,
                KEY_WRITE,
                &hKey,
                &outKey,
                0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else {
                printLine("Registry key opened successfully");
            }
        }
#endif
    }
}

void CWE272_Least_Privilege_Principal__wchar_t_w32SHRegOpenUSKey_12_good()
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
    CWE272_Least_Privilege_Principal__wchar_t_w32SHRegOpenUSKey_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__wchar_t_w32SHRegOpenUSKey_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
