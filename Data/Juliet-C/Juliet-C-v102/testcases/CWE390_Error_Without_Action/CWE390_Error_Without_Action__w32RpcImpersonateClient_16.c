/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__w32RpcImpersonateClient_16.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: w32RpcImpersonateClient
 *    GoodSink: Check the return value of RpcImpersonateClient() and handle errors properly
 *    BadSink : Check the return value of RpcImpersonateClient(), but fail to handle errors
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

#ifndef OMITBAD

void CWE390_Error_Without_Action__w32RpcImpersonateClient_16_bad()
{
    while(1)
    {
        {
            /* FLAW: Check the return value of RpcImpersonateClient() for RPC_S_OK, but do not handle errors */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                /* do nothing */
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK and handle errors */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
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
        {
            /* FLAW: Check the return value of RpcImpersonateClient() for RPC_S_OK, but do not handle errors */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                /* do nothing */
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
        break;
    }
    while(1)
    {
        {
            /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK and handle errors */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
        break;
    }
}

void CWE390_Error_Without_Action__w32RpcImpersonateClient_16_good()
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
    CWE390_Error_Without_Action__w32RpcImpersonateClient_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__w32RpcImpersonateClient_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
