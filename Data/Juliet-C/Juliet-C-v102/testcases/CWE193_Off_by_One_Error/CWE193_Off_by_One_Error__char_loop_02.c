/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__char_loop_02.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: loop
 *    GoodSink: Use a loop to perform a string copy without overflowing the destination buffer
 *    BadSink : Use a loop to perform a string copy, but overflow the destination buffer
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR "AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__char_loop_02_bad()
{
    if(1)
    {
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FLAW: did <= instead of < in copy (index is off-by-one)
             * INCIDENTAL CWE121 - Stack Based Buffer Overflow
             */
            for (i = 0; i <= DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FIX: use <, ensures we do not write out of bounds */
            for (i = 0; i < DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FLAW: did <= instead of < in copy (index is off-by-one)
             * INCIDENTAL CWE121 - Stack Based Buffer Overflow
             */
            for (i = 0; i <= DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
    else
    {
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FIX: use <, ensures we do not write out of bounds */
            for (i = 0; i < DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FIX: use <, ensures we do not write out of bounds */
            for (i = 0; i < DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            size_t i;
            char dst[DST_SZ];
            const char *src = COPY_STR;
            /* FLAW: did <= instead of < in copy (index is off-by-one)
             * INCIDENTAL CWE121 - Stack Based Buffer Overflow
             */
            for (i = 0; i <= DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = '\0'; /* null terminate */
            printLine(dst);
        }
    }
}

void CWE193_Off_by_One_Error__char_loop_02_good()
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
    CWE193_Off_by_One_Error__char_loop_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__char_loop_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
