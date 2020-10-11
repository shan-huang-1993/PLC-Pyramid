/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__char_memcpy_05.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: memcpy
 *    GoodSink: Use memcpy() to perform a string copy correctly
 *    BadSink : Use memcpy() to perform a string copy, but copy one too many characters
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR "AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__char_memcpy_05_bad()
{
    if(static_t)
    {
        {
            char dst[DST_SZ];
            /* FLAW: Passed DST_SZ to memcpy() */
            memcpy(dst, COPY_STR, DST_SZ*sizeof(char));
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            /* FIX: memcpy the correct amount */
            memcpy(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
            /* null terminate the string */
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
            /* FLAW: Passed DST_SZ to memcpy() */
            memcpy(dst, COPY_STR, DST_SZ*sizeof(char));
            printLine(dst);
        }
    }
    else
    {
        {
            char dst[DST_SZ];
            /* FIX: memcpy the correct amount */
            memcpy(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
            /* null terminate the string */
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
            /* FIX: memcpy the correct amount */
            memcpy(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
            /* null terminate the string */
            dst[DST_SZ-1] = '\0';
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dst[DST_SZ];
            /* FLAW: Passed DST_SZ to memcpy() */
            memcpy(dst, COPY_STR, DST_SZ*sizeof(char));
            printLine(dst);
        }
    }
}

void CWE193_Off_by_One_Error__char_memcpy_05_good()
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
    CWE193_Off_by_One_Error__char_memcpy_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__char_memcpy_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
