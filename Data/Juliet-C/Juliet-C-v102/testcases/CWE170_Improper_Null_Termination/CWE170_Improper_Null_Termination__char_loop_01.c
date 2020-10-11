/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE170_Improper_Null_Termination__char_loop_01.c
Label Definition File: CWE170_Improper_Null_Termination.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 170 Improper Null Termination
 * Sinks: loop
 *    GoodSink: Copy a string using a loop with explicit null termination
 *    BadSink : Copy a string using a loop without explicit null termination
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE170_Improper_Null_Termination__char_loop_01_bad()
{
    {
        char src[150], dest[100];
        int i;
        /* Initialize src */
        memset(src, 'A', 149);
        src[149] = '\0';
        for(i=0; i < 100; i++)
        {
            dest[i] = src[i];
        }
        /* FLAW: do not explicitly null terminate dest after the loop */
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char src[150], dest[100];
        int i;
        /* Initialize src */
        memset(src, 'A', 149);
        src[149] = '\0';
        for(i=0; i < 100; i++)
        {
            dest[i] = src[i];
        }
        dest[99] = '\0'; /* FIX: null terminate dest */
        printLine(dest);
    }
}

void CWE170_Improper_Null_Termination__char_loop_01_good()
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
    CWE170_Improper_Null_Termination__char_loop_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE170_Improper_Null_Termination__char_loop_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif