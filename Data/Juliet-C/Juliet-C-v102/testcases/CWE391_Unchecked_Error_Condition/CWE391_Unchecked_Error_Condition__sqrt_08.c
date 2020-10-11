/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_08.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>

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

void CWE391_Unchecked_Error_Condition__sqrt_08_bad()
{
    if(static_returns_t())
    {
        {
            double d = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(d);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed */
            if (err_code == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(d);
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
        {
            double d = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(d);
        }
    }
    else
    {
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed */
            if (err_code == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(d);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed */
            if (err_code == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(d);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            double d = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(d);
        }
    }
}

void CWE391_Unchecked_Error_Condition__sqrt_08_good()
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
    CWE391_Unchecked_Error_Condition__sqrt_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__sqrt_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
