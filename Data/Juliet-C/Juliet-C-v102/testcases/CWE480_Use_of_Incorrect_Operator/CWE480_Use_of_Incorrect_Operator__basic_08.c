/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE480_Use_of_Incorrect_Operator__basic_08.c
Label Definition File: CWE480_Use_of_Incorrect_Operator__basic.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 480 Use of Incorrect Operator
 * Sinks:
 *    GoodSink: Include parens
 *    BadSink : Forget parens
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

static char* CWE480_Use_of_Incorrect_Operator__basic_08_string_bad = "Hello";
static char* CWE480_Use_of_Incorrect_Operator__basic_08_string_good = "Hello";

static char * helper_bad()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return CWE480_Use_of_Incorrect_Operator__basic_08_string_bad;
    }
}

static char * helper_good()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return CWE480_Use_of_Incorrect_Operator__basic_08_string_good;
    }
}

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE480_Use_of_Incorrect_Operator__basic_08_bad()
{
    if(static_returns_t())
    {
        /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
        if(helper_bad == NULL)
        {
            printLine("Got a NULL");
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: add () to function call */
        if(helper_good() == NULL)   /* this will sometimes be true (depending on the rand() in helper_good) */
        {
            printLine("Got a NULL");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
        if(helper_bad == NULL)
        {
            printLine("Got a NULL");
        }
    }
    else
    {
        /* FIX: add () to function call */
        if(helper_good() == NULL)   /* this will sometimes be true (depending on the rand() in helper_good) */
        {
            printLine("Got a NULL");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        /* FIX: add () to function call */
        if(helper_good() == NULL)   /* this will sometimes be true (depending on the rand() in helper_good) */
        {
            printLine("Got a NULL");
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
        if(helper_bad == NULL)
        {
            printLine("Got a NULL");
        }
    }
}

void CWE480_Use_of_Incorrect_Operator__basic_08_good()
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
    CWE480_Use_of_Incorrect_Operator__basic_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE480_Use_of_Incorrect_Operator__basic_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif