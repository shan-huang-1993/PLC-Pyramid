/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_18.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UNLINK _unlink
# define FOPEN fopen
#else
# define UNLINK unlink
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__char_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        FILE *f;
        f = FOPEN("temp.txt", "w");
        if (f != NULL)
        {
            fprintf(f, "Temporary file");
            fclose(f);
            /* FIX: Unlink the temporary file */
            UNLINK("temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
        }
    }
sink:
    {
        FILE *f;
        f = FOPEN("temp.txt", "w");
        if (f != NULL)
        {
            fprintf(f, "Temporary file");
            fclose(f);
            /* FLAW: We don't unlink */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        FILE *f;
        f = FOPEN("temp.txt", "w");
        if (f != NULL)
        {
            fprintf(f, "Temporary file");
            fclose(f);
            /* FLAW: We don't unlink */
        }
    }
sink:
    {
        FILE *f;
        f = FOPEN("temp.txt", "w");
        if (f != NULL)
        {
            fprintf(f, "Temporary file");
            fclose(f);
            /* FIX: Unlink the temporary file */
            UNLINK("temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
        }
    }
}

void CWE459_Incomplete_Cleanup__char_18_good()
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
    CWE459_Incomplete_Cleanup__char_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__char_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
