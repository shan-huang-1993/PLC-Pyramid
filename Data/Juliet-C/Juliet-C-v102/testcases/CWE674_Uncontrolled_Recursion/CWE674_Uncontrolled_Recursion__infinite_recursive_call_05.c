/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE674_Uncontrolled_Recursion__infinite_recursive_call_05.c
Label Definition File: CWE674_Uncontrolled_Recursion.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 674 Uncontrolled Recursion
 * Sinks: infinite_recursive_call
 *    GoodSink: The function has a lower bound thus preventing infinite recursion
 *    BadSink : Function does not have a bound causing infinite recursion
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
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

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_05_bad()
{
    if(static_t)
    {
        helper_bad();
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_good(5);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad();
    }
    else
    {
        helper_good(5);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        helper_good(5);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad();
    }
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_05_good()
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
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
