/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE196_Unsigned_To_Signed_Conversion_Error__basic_18.c
Label Definition File: CWE196_Unsigned_To_Signed_Conversion_Error__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 196 Unsigned To Signed Conversion Error
 * Sinks:
 *    GoodSink: Don't allow very large values of u
 *    BadSink : Convert a possibly large unsigned int (larger than INT_MAX) to an int
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE196_Unsigned_To_Signed_Conversion_Error__basic_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        unsigned u;
        int i;
        u = rand();
        if (rand() % 2 == 0)
        {
            u = UINT_MAX - u;
        }
        /* FIX: don't allow very large values of u */
        if (u > INT_MAX) exit(1);
        i = u;
        printIntLine(i);
    }
sink:
    {
        unsigned u;
        int i;
        u = rand();
        if (rand() % 2 == 0)
        {
            u = UINT_MAX - u;
        }
        /* FLAW: u could be very large, in which case i will be negative */
        i = u;
        printIntLine(i);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        unsigned u;
        int i;
        u = rand();
        if (rand() % 2 == 0)
        {
            u = UINT_MAX - u;
        }
        /* FLAW: u could be very large, in which case i will be negative */
        i = u;
        printIntLine(i);
    }
sink:
    {
        unsigned u;
        int i;
        u = rand();
        if (rand() % 2 == 0)
        {
            u = UINT_MAX - u;
        }
        /* FIX: don't allow very large values of u */
        if (u > INT_MAX) exit(1);
        i = u;
        printIntLine(i);
    }
}

void CWE196_Unsigned_To_Signed_Conversion_Error__basic_18_good()
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
    CWE196_Unsigned_To_Signed_Conversion_Error__basic_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE196_Unsigned_To_Signed_Conversion_Error__basic_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
