/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_putc_17.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: putc
 *    GoodSink: Check if putc() failed and handle errors properly
 *    BadSink : Check to see if putc() failed, but do nothing about it
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_putc_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (putc((int)'A', stdout) == EOF)
            {
                /* do nothing */
            }
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value and handle errors properly */
            if (putc((int)'A', stdout) == EOF)
            {
                printLine("putc failed!");
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (putc((int)'A', stdout) == EOF)
            {
                /* do nothing */
            }
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (putc((int)'A', stdout) == EOF)
            {
                printLine("putc failed!");
                exit(1);
            }
        }
    }
}

void CWE390_Error_Without_Action__char_putc_17_good()
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
    CWE390_Error_Without_Action__char_putc_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_putc_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
