/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE365_Race_Condition_In_Switch__basic_16.c
Label Definition File: CWE365_Race_Condition_In_Switch__basic.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 365 Race Condition in Switch
 * Sinks:
 *    GoodSink: Switch based on call to time() using a temporary variable
 *    BadSink : Switch based on call to time()
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <time.h>

#ifndef OMITBAD

void CWE365_Race_Condition_In_Switch__basic_16_bad()
{
    while(1)
    {
        /* FLAW: switch-ing based on a call to 'time(NULL)' which could change
         * from one call to the next (when the clock is near a second-boundary)
         */
        switch (time(NULL) % 4)
        {
        case 0:
            printLine("0");
            break;
        case 1:
            printLine("1");
            break;
        default:
            printLine("default");
            break;
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            time_t time_val = time(NULL);
            /* FIX: assign to a temporary prior to calling */
            switch (time_val % 4)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            default:
                printLine("default");
                break;
            }
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
        /* FLAW: switch-ing based on a call to 'time(NULL)' which could change
         * from one call to the next (when the clock is near a second-boundary)
         */
        switch (time(NULL) % 4)
        {
        case 0:
            printLine("0");
            break;
        case 1:
            printLine("1");
            break;
        default:
            printLine("default");
            break;
        }
        break;
    }
    while(1)
    {
        {
            time_t time_val = time(NULL);
            /* FIX: assign to a temporary prior to calling */
            switch (time_val % 4)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            default:
                printLine("default");
                break;
            }
        }
        break;
    }
}

void CWE365_Race_Condition_In_Switch__basic_16_good()
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
    CWE365_Race_Condition_In_Switch__basic_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE365_Race_Condition_In_Switch__basic_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
