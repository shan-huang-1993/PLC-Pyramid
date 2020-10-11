/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_fwrite_05.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fwrite
 *    GoodSink: Check if fwrite() failed and handle errors properly
 *    BadSink : Check to see if fwrite() failed, but do nothing about it
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_fwrite_05_bad()
{
    if(static_t)
    {
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value and handle errors properly */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
                exit(1);
            }
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
            /* FLAW: check the return value, but do nothing if there is an error */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                /* do nothing */
            }
        }
    }
    else
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                /* do nothing */
            }
        }
    }
}

void CWE390_Error_Without_Action__char_fwrite_05_good()
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
    CWE390_Error_Without_Action__char_fwrite_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_fwrite_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
