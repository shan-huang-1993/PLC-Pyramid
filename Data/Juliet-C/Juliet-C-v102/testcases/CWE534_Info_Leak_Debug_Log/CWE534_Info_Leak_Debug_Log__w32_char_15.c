/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE534_Info_Leak_Debug_Log__w32_char_15.c
Label Definition File: CWE534_Info_Leak_Debug_Log__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 534 Information Leak Through Debug Log Files
 * Sinks:
 *    GoodSink: Write to the log, but do not write the password
 *    BadSink : Write to the log and include the password
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE534_Info_Leak_Debug_Log__w32_char_15_bad()
{
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FLAW: Write sensitive data to the log */
        fprintf(file, "User attempted access with password: %s\n", password);
        fclose(file);
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FIX: Do not write sensitive data to the log */
        fprintf(file, "User attempted access\n");
        fclose(file);
#endif
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
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FLAW: Write sensitive data to the log */
        fprintf(file, "User attempted access with password: %s\n", password);
        fclose(file);
#endif
    }
    break;
    default:
    {
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FIX: Do not write sensitive data to the log */
        fprintf(file, "User attempted access\n");
        fclose(file);
#endif
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
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FIX: Do not write sensitive data to the log */
        fprintf(file, "User attempted access\n");
        fclose(file);
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
#ifdef _WIN32 /* this is WIN32 specific */
        char password[100] = "";
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        FILE * file = fopen("debug.txt", "a+");
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserA(
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
        /* FLAW: Write sensitive data to the log */
        fprintf(file, "User attempted access with password: %s\n", password);
        fclose(file);
#endif
    }
    }
}

void CWE534_Info_Leak_Debug_Log__w32_char_15_good()
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
    CWE534_Info_Leak_Debug_Log__w32_char_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE534_Info_Leak_Debug_Log__w32_char_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
