/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE242_Use_of_Inherently_Dangerous_Function__basic_05.c
Label Definition File: CWE242_Use_of_Inherently_Dangerous_Function__basic.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 242 Use of Inherently Dangerous Function
 * Sinks:
 *    GoodSink: Use fgets() for bounded user input
 *    BadSink : Use gets() for user input
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 10

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE242_Use_of_Inherently_Dangerous_Function__basic_05_bad()
{
    if(static_t)
    {
        {
            char dst[DST_SZ];
            char *result;
            /* FLAW: gets is inherently dangerous and cannot be used safely. */
            /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
             * an unbounded copy. */
            result = gets(dst);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            char *result;
            /* FIX: use fgets for bounded read from stdin*/
            result = fgets(dst, DST_SZ, stdin);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
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
        {
            char dst[DST_SZ];
            char *result;
            /* FLAW: gets is inherently dangerous and cannot be used safely. */
            /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
             * an unbounded copy. */
            result = gets(dst);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
    else
    {
        {
            char dst[DST_SZ];
            char *result;
            /* FIX: use fgets for bounded read from stdin*/
            result = fgets(dst, DST_SZ, stdin);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            char dst[DST_SZ];
            char *result;
            /* FIX: use fgets for bounded read from stdin*/
            result = fgets(dst, DST_SZ, stdin);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            char *result;
            /* FLAW: gets is inherently dangerous and cannot be used safely. */
            /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
             * an unbounded copy. */
            result = gets(dst);
            /* Verify return value */
            if( NULL == result )
            {
                /* error condition */
                printLine("Error Condition: alter control flow to indicate action taken");
                exit(1);
            }
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
}

void CWE242_Use_of_Inherently_Dangerous_Function__basic_05_good()
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
    CWE242_Use_of_Inherently_Dangerous_Function__basic_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE242_Use_of_Inherently_Dangerous_Function__basic_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
