/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__sqrt_11.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sqrt
 *    GoodSink: Check to see if sqrt() failed and handle errors properly
 *    BadSink : Check to see if sqrt() failed, but fail to handle errors
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <errno.h>

#ifndef OMITBAD

void CWE390_Error_Without_Action__sqrt_11_bad()
{
    if(global_returns_t())
    {
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FLAW: Check errno to see if sqrt() failed, but do nothing about it */
            if (err_code == EDOM)
            {
                /* do nothing */
            }
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
            /* FIX: Check errno to see if sqrt() failed and handle errors properly */
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

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
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
            /* FLAW: Check errno to see if sqrt() failed, but do nothing about it */
            if (err_code == EDOM)
            {
                /* do nothing */
            }
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
            /* FIX: Check errno to see if sqrt() failed and handle errors properly */
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
    if(global_returns_t())
    {
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed and handle errors properly */
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
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FLAW: Check errno to see if sqrt() failed, but do nothing about it */
            if (err_code == EDOM)
            {
                /* do nothing */
            }
            printDoubleLine(d);
        }
    }
}

void CWE390_Error_Without_Action__sqrt_11_good()
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
    CWE390_Error_Without_Action__sqrt_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__sqrt_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
