/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic_15.c
Label Definition File: CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 688 Function Call With Incorrect Variable or Reference As Argument
 * Sinks:
 *    GoodSink: Use the correct format to print a string
 *    BadSink : Use a string format to print an int
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 100

#ifndef OMITBAD

void CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char dst[DST_SZ];
        int x = 5;
        /* FLAW: int argument passed, expecting string argument */
        sprintf(dst, "%s", x);
        printLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        int x = 5;
        /* FIX: use the correct format string */
        sprintf(dst, "%d", x);
        printLine(dst);
    }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        int x = 5;
        /* FLAW: int argument passed, expecting string argument */
        sprintf(dst, "%s", x);
        printLine(dst);
    }
    break;
    default:
    {
        char dst[DST_SZ];
        int x = 5;
        /* FIX: use the correct format string */
        sprintf(dst, "%d", x);
        printLine(dst);
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        char dst[DST_SZ];
        int x = 5;
        /* FIX: use the correct format string */
        sprintf(dst, "%d", x);
        printLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        int x = 5;
        /* FLAW: int argument passed, expecting string argument */
        sprintf(dst, "%s", x);
        printLine(dst);
    }
    }
}

void CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic_15_good()
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
    CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE688_Function_Call_With_Incorrect_Variable_Or_Reference_As_Argument__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
