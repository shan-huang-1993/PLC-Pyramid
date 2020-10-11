/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__char_ncpy_19.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: ncpy
 *    GoodSink: Use strncpy() to perform a string copy correctly
 *    BadSink : Use strncpy() to perform a string copy, but copy one too many characters
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR "AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__char_ncpy_19_bad()
{
    {
        char dst[DST_SZ];
        /* FLAW: Passed DST_SZ to strncpy */
        strncpy(dst, COPY_STR, DST_SZ);
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        /* FIX: strncpy the correct amount */
        strncpy(dst, COPY_STR, DST_SZ-1);
        /* null terminate the string to make tools happy, even though it is unnecessary here */
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        char dst[DST_SZ];
        /* FIX: strncpy the correct amount */
        strncpy(dst, COPY_STR, DST_SZ-1);
        /* null terminate the string to make tools happy, even though it is unnecessary here */
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        /* FLAW: Passed DST_SZ to strncpy */
        strncpy(dst, COPY_STR, DST_SZ);
        printLine(dst);
    }
}

void CWE193_Off_by_One_Error__char_ncpy_19_good()
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
    CWE193_Off_by_One_Error__char_ncpy_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__char_ncpy_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
