/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE674_Uncontrolled_Recursion__infinite_recursive_call_16.c
Label Definition File: CWE674_Uncontrolled_Recursion.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 674 Uncontrolled Recursion
 * Sinks: infinite_recursive_call
 *    GoodSink: The function has a lower bound thus preventing infinite recursion
 *    BadSink : Function does not have a bound causing infinite recursion
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

static void helper_bad()
{
    /* FLAW: this function causes infinite recursion */
    helper_bad(); /* maintenance note: this may generate a warning, this is on purpose */
}

static void helper_good(unsigned level)
{
    /* FIX: provide lower-bound for recurssion stop */
    if (level == 0)
    {
        return;
    }
    helper_good(level - 1);
}

#ifndef OMITBAD

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_16_bad()
{
    while(1)
    {
        helper_bad();
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_good(5);
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
        helper_bad();
        break;
    }
    while(1)
    {
        helper_good(5);
        break;
    }
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_16_good()
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
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
