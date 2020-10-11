/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__w32RpcImpersonateClient_08.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32RpcImpersonateClient
 *    GoodSink: Correctly check if RpcImpersonateClient() fails
 *    BadSink : Incorrectly check if RpcImpersonateClient() fails
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

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

void CWE253_Incorrect_Check_of_Return_Value__w32RpcImpersonateClient_08_bad()
{
    if(static_returns_t())
    {
        {
            RpcImpersonateClient(0);
            /* FLAW: RpcImpersonateClient() could fail and would not return RPC_S_OK, but we
               are failing if the return value is RPC_S_OK */
            if (RpcImpersonateClient(0) == RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
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
        {
            RpcImpersonateClient(0);
            /* FLAW: RpcImpersonateClient() could fail and would not return RPC_S_OK, but we
               are failing if the return value is RPC_S_OK */
            if (RpcImpersonateClient(0) == RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            /* FIX: check for the correct return value */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            RpcImpersonateClient(0);
            /* FLAW: RpcImpersonateClient() could fail and would not return RPC_S_OK, but we
               are failing if the return value is RPC_S_OK */
            if (RpcImpersonateClient(0) == RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__w32RpcImpersonateClient_08_good()
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
    CWE253_Incorrect_Check_of_Return_Value__w32RpcImpersonateClient_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__w32RpcImpersonateClient_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
