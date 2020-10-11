/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE248_Uncaught_Exception__throw_no_catch_01.cpp
Label Definition File: CWE248_Uncaught_Exception.label.xml
Template File: point-flaw-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 248 Uncaught Exception
 * Sinks: throw_no_catch
 *    GoodSink: Throw and catch an exception
 *    BadSink : Throw an exception
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <stdexcept>

using namespace std;

namespace CWE248_Uncaught_Exception__throw_no_catch_01
{

#ifndef OMITBAD

void bad()
{
    {
        /* FLAW: Throw an exception, but do not catch */
        throw 25;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
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

void good()
{
    good1();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE248_Uncaught_Exception__throw_no_catch_01; // so that we can use good and bad easily

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
