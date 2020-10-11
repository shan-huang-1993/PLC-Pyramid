/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__wchar_t_17.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UNLINK _wunlink
# define FOPEN _wfopen
#else
# define UNLINK wunlink
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__wchar_t_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            FILE *f;
            f = FOPEN(L"temp.txt", L"w");
            if (f != NULL)
            {
                fwprintf(f, L"Temporary file");
                fclose(f);
                /* FLAW: We don't unlink */
            }
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *f;
            f = FOPEN(L"temp.txt", L"w");
            if (f != NULL)
            {
                fwprintf(f, L"Temporary file");
                fclose(f);
                /* FIX: Unlink the temporary file */
                UNLINK(L"temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *f;
            f = FOPEN(L"temp.txt", L"w");
            if (f != NULL)
            {
                fwprintf(f, L"Temporary file");
                fclose(f);
                /* FLAW: We don't unlink */
            }
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            FILE *f;
            f = FOPEN(L"temp.txt", L"w");
            if (f != NULL)
            {
                fwprintf(f, L"Temporary file");
                fclose(f);
                /* FIX: Unlink the temporary file */
                UNLINK(L"temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

void CWE459_Incomplete_Cleanup__wchar_t_17_good()
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
    CWE459_Incomplete_Cleanup__wchar_t_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__wchar_t_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
