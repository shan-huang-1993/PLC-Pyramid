/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE674_Uncontrolled_Recursion__infinite_recursive_call_12.c
Label Definition File: CWE674_Uncontrolled_Recursion.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 674 Uncontrolled Recursion
 * Sinks: infinite_recursive_call
 *    GoodSink: The function has a lower bound thus preventing infinite recursion
 *    BadSink : Function does not have a bound causing infinite recursion
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
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

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_12_bad()
{
    if(global_returns_t_or_f())
    {
        helper_bad();
    }
    else
    {
        helper_good(5);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        helper_good(5);
    }
    else
    {
        helper_good(5);
    }
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_12_good()
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
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
