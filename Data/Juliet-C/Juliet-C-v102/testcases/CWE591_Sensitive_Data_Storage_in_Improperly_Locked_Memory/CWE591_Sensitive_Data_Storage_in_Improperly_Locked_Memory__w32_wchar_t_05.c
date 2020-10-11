/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_05.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_05_bad()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
    if(static_t)
    {
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FLAW: Do not lock the memory */
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32 /* this is WIN32 specific */
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FIX: Use VirtualLock() to lock the buffer into memory */
        if(!VirtualLock(password, 100*sizeof(wchar_t)))
        {
            printLine("Memory could not be locked");
            exit(1);
        }
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
#endif
    }
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FLAW: Do not lock the memory */
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
    }
    else
    {
#ifdef _WIN32 /* this is WIN32 specific */
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FIX: Use VirtualLock() to lock the buffer into memory */
        if(!VirtualLock(password, 100*sizeof(wchar_t)))
        {
            printLine("Memory could not be locked");
            exit(1);
        }
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
#endif
    }
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
#endif
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
    if(static_t)
    {
#ifdef _WIN32 /* this is WIN32 specific */
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FIX: Use VirtualLock() to lock the buffer into memory */
        if(!VirtualLock(password, 100*sizeof(wchar_t)))
        {
            printLine("Memory could not be locked");
            exit(1);
        }
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        /* FLAW: Do not lock the memory */
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
    }
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
#endif
    }
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_05_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
