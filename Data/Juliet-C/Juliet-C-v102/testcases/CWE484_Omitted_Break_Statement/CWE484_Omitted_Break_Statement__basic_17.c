/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement__basic_17.c
Label Definition File: CWE484_Omitted_Break_Statement__basic.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : No break at the end of cases
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE484_Omitted_Break_Statement__basic_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            int x;
            x = (rand() % 3);
            /* FLAW: None of these cases ends in a break */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
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
            int x;
            x = (rand() % 3);
            /* FLAW: None of these cases ends in a break */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            int x;
            x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
                /* no default case, but there shouldn't be one */
            }
        }
    }
}

void CWE484_Omitted_Break_Statement__basic_17_good()
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
    CWE484_Omitted_Break_Statement__basic_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE484_Omitted_Break_Statement__basic_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif