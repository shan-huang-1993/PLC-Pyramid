/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__wcstombs_01.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: wcstombs
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if wcstombs() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__wcstombs_01_bad()
{
    {
        size_t st = 0;
        char str[100];
        str[0] = '\0';
        st = wcstombs((char *)&str, L"\xffff", 100);
        /* FLAW: Do not check to see if wcstombs() failed */
        printUnsignedLine(st);
        printLine(str);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        errno_t err_code = -1;
        size_t st = 0;
        char str[100];
        str[0] = '\0';
        st = wcstombs((char *)&str, L"\xffff", 100);
        if (_get_errno(&err_code))
        {
            printLine("_get_errno failed");
            exit(1);
        }
        /* FIX: Check errno to see if wcstombs() failed */
        if (err_code == EILSEQ)
        {
            printLine("wcstombs() failed");
            exit(1);
        }
        printUnsignedLine(st);
        printLine(str);
    }
}

void CWE391_Unchecked_Error_Condition__wcstombs_01_good()
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
    CWE391_Unchecked_Error_Condition__wcstombs_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__wcstombs_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
