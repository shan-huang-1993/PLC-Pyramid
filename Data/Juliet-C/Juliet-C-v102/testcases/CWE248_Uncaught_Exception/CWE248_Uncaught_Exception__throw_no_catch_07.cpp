/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE248_Uncaught_Exception__throw_no_catch_07.cpp
Label Definition File: CWE248_Uncaught_Exception.label.xml
Template File: point-flaw-07.tmpl.cpp
*/
/*
 * @description
 * CWE: 248 Uncaught Exception
 * Sinks: throw_no_catch
 *    GoodSink: Throw and catch an exception
 *    BadSink : Throw an exception
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#include <stdexcept>

using namespace std;

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

namespace CWE248_Uncaught_Exception__throw_no_catch_07
{

#ifndef OMITBAD

void bad()
{
    if(static_five==5)
    {
        {
            /* FLAW: Throw an exception, but do not catch */
            throw 25;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            try
            {
                throw 25;
            }
            /* FIX: Catch the exception throw in the try block */
            catch (int e)
            {
                printLine("Exception caught - value: ");
                printIntLine(e);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_five!=5) instead of if(static_five==5) */
static void good1()
{
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Throw an exception, but do not catch */
            throw 25;
        }
    }
    else
    {
        {
            try
            {
                throw 25;
            }
            /* FIX: Catch the exception throw in the try block */
            catch (int e)
            {
                printLine("Exception caught - value: ");
                printIntLine(e);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_five==5)
    {
        {
            try
            {
                throw 25;
            }
            /* FIX: Catch the exception throw in the try block */
            catch (int e)
            {
                printLine("Exception caught - value: ");
                printIntLine(e);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Throw an exception, but do not catch */
            throw 25;
        }
    }
}

void good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE248_Uncaught_Exception__throw_no_catch_07; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
