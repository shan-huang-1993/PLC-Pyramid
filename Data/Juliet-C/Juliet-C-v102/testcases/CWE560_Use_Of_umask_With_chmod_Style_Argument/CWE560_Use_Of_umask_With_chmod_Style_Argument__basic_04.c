/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_04.c
Label Definition File: CWE560_Use_Of_umask_With_chmod_Style_Argument__basic.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 560 Use Of umask With chmod Style Argument
 * Sinks:
 *    GoodSink: Use umask() correctly
 *    BadSink : Use umask() incorrectly - the bits sent to umask() are bitwise-negated
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UMASK _umask
#else
# define UMASK umask
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_04_bad()
{
    if(static_const_t)
    {
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the appropriate umask */
        UMASK(022);
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
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
    else
    {
        /* FIX: Use the appropriate umask */
        UMASK(022);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        /* FIX: Use the appropriate umask */
        UMASK(022);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
}

void CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_04_good()
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
    CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
