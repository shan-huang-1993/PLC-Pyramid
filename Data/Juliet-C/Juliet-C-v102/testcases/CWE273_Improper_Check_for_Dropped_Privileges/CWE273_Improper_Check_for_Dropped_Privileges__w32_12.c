/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_12.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks:
 *    GoodSink: Check if ImpersonateNamedPipeClient() succeeded or not
 *    BadSink : Failed to check return status of ImpersonateNamedPipeClient()
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <windows.h>
# pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE273_Improper_Check_for_Dropped_Privileges__w32_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pipe = INVALID_HANDLE_VALUE;
            pipe = CreateNamedPipeA(
                       "\\\\.\\pipe\\test_pipe",
                       PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                       PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                       1,
                       0,
                       0,
                       0,
                       0);
            if (pipe == INVALID_HANDLE_VALUE) exit(1);
            if (!ConnectNamedPipe(pipe, 0))
            {
                CloseHandle(pipe);
                exit(1);
            }
            /* FLAW: Failed to check return status of ImpersonateNamedPipeClient
             * -- However, since we're not even DOING anything with the pipe
             * it's debatable whether this is really a bug
             */
            ImpersonateNamedPipeClient(pipe);
            printLine("Impersonated");
            if (!RevertToSelf())
            {
                exit(1);
            }
            CloseHandle(pipe);
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pipe = INVALID_HANDLE_VALUE;
            pipe = CreateNamedPipeA(
                       "\\\\.\\pipe\\test_pipe",
                       PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                       PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                       1,
                       0,
                       0,
                       0,
                       0);
            if (pipe == INVALID_HANDLE_VALUE)
            {
                printf("%d\n",GetLastError());
                exit(1);
            }
            if (!ConnectNamedPipe(pipe, 0))
            {
                CloseHandle(pipe);
                exit(1);
            }
            /* FIX: Check if "ImpersonateNamedPipeClient" succeeded or not */
            if (!ImpersonateNamedPipeClient(pipe))
            {
                printLine("Failed to impersonate");
            }
            else
            {
                printLine("Impersonated");
                if (!RevertToSelf())
                {
                    exit(1);
                }
            }
            CloseHandle(pipe);
#endif /* _WIN32 */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pipe = INVALID_HANDLE_VALUE;
            pipe = CreateNamedPipeA(
                       "\\\\.\\pipe\\test_pipe",
                       PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                       PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                       1,
                       0,
                       0,
                       0,
                       0);
            if (pipe == INVALID_HANDLE_VALUE)
            {
                printf("%d\n",GetLastError());
                exit(1);
            }
            if (!ConnectNamedPipe(pipe, 0))
            {
                CloseHandle(pipe);
                exit(1);
            }
            /* FIX: Check if "ImpersonateNamedPipeClient" succeeded or not */
            if (!ImpersonateNamedPipeClient(pipe))
            {
                printLine("Failed to impersonate");
            }
            else
            {
                printLine("Impersonated");
                if (!RevertToSelf())
                {
                    exit(1);
                }
            }
            CloseHandle(pipe);
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pipe = INVALID_HANDLE_VALUE;
            pipe = CreateNamedPipeA(
                       "\\\\.\\pipe\\test_pipe",
                       PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                       PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                       1,
                       0,
                       0,
                       0,
                       0);
            if (pipe == INVALID_HANDLE_VALUE)
            {
                printf("%d\n",GetLastError());
                exit(1);
            }
            if (!ConnectNamedPipe(pipe, 0))
            {
                CloseHandle(pipe);
                exit(1);
            }
            /* FIX: Check if "ImpersonateNamedPipeClient" succeeded or not */
            if (!ImpersonateNamedPipeClient(pipe))
            {
                printLine("Failed to impersonate");
            }
            else
            {
                printLine("Impersonated");
                if (!RevertToSelf())
                {
                    exit(1);
                }
            }
            CloseHandle(pipe);
#endif /* _WIN32 */
        }
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_12_good()
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
    CWE273_Improper_Check_for_Dropped_Privileges__w32_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
