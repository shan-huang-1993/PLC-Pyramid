/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE674_Uncontrolled_Recursion__unbounded_recursive_call_04.c
Label Definition File: CWE674_Uncontrolled_Recursion.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 674 Uncontrolled Recursion
 * Sinks: unbounded_recursive_call
 *    GoodSink: Limit recursion to a managed level
 *    BadSink : Recursion not limited to a managed level
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

static void helper_bad(unsigned level)
{
    /* FLAW: Although this cannot cause "infinite" recursion, it is essentially limited to UINT_MAX
     * which is rather large on most systems
     */
    if (level == 0) return;
    helper_bad(level - 1);
}

#define MAX_RECURSION 10

static void helper_good(unsigned level)
{
    /* FIX: limit recursion to a sane level */
    if (level > MAX_RECURSION)
    {
        printLine("ERROR IN RECURSION");
        return;
    }
    if (level == 0)
    {
        return;
    }
    helper_good(level - 1);
}

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_04_bad()
{
    if(static_const_t)
    {
        helper_bad(UINT_MAX);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_good(UINT_MAX);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad(UINT_MAX);
    }
    else
    {
        helper_good(UINT_MAX);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        helper_good(UINT_MAX);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad(UINT_MAX);
    }
}

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_04_good()
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
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
