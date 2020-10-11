/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__char_w32SHRegOpenUSKey_16.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32SHRegOpenUSKey
 *    GoodSink: Open a registry key using SHRegOpenUSKeyA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using SHRegOpenUSKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__char_w32SHRegOpenUSKey_16_bad()
{
    while(1)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;
            HUSKEY outKey;

            /* FLAW: Call SHRegOpenUSKeyA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegOpenUSKeyA(
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
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            HUSKEY outKey;
            /* FIX: Call SHRegOpenUSKeyA() with HKEY_CURRENT_USER */
            if (SHRegOpenUSKeyA(
                        key,
                        KEY_WRITE,
                        &hKey,
                        &outKey,
                        0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
            }
        }
#endif
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
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;
            HUSKEY outKey;
            /* FLAW: Call SHRegOpenUSKeyA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegOpenUSKeyA(
                        key,
                        KEY_WRITE,
                        &hKey,
                        &outKey,
                        0) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
            }
        }
#endif
        break;
    }
    while(1)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            HUSKEY outKey;

            /* FIX: Call SHRegOpenUSKeyA() with HKEY_CURRENT_USER */
            if (SHRegOpenUSKeyA(
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
        break;
    }
}

void CWE272_Least_Privilege_Principal__char_w32SHRegOpenUSKey_16_good()
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
    CWE272_Least_Privilege_Principal__char_w32SHRegOpenUSKey_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__char_w32SHRegOpenUSKey_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
