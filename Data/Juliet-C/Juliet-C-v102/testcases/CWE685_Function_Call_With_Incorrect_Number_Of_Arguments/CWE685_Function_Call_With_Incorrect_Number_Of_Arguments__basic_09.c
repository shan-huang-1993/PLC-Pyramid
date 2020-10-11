/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic_09.c
Label Definition File: CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 685 Function Call With Incorrect Number of Arguments
 * Sinks:
 *    GoodSink: Use the correct number of arguments
 *    BadSink : Incorrect number of arguments
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 100 /* maintenance note: ensure this is > 2*SRC_STR to avoid buffer overflow issues */
#define SRC_STR "AAA"

#ifndef OMITBAD

void CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic_09_bad()
{
    if(global_const_t)
    {
        {
            char dst[DST_SZ];
            /* FLAW: Incorrect number of arguments */
            sprintf(dst, "%s %s", SRC_STR);
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            /* FIX: Use the correct number of arguments */
            sprintf(dst, "%s %s", SRC_STR, SRC_STR);
            printLine(dst);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            /* FLAW: Incorrect number of arguments */
            sprintf(dst, "%s %s", SRC_STR);
            printLine(dst);
        }
    }
    else
    {
        {
            char dst[DST_SZ];
            /* FIX: Use the correct number of arguments */
            sprintf(dst, "%s %s", SRC_STR, SRC_STR);
            printLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        {
            char dst[DST_SZ];
            /* FIX: Use the correct number of arguments */
            sprintf(dst, "%s %s", SRC_STR, SRC_STR);
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            /* FLAW: Incorrect number of arguments */
            sprintf(dst, "%s %s", SRC_STR);
            printLine(dst);
        }
    }
}

void CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic_09_good()
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
    CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE685_Function_Call_With_Incorrect_Number_Of_Arguments__basic_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
