/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_43.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_43
{

#ifndef OMITBAD

void bad_source(twointsclass &data)
{
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    twointsclass data;
    bad_source(data);
    printIntLine(data.a);
    printIntLine(data.b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_source(twointsclass &data)
{
    data.a = 1;
    data.b = 2;
}

static void goodG2B()
{
    twointsclass data;
    goodG2B_source(data);
    printIntLine(data.a);
    printIntLine(data.b);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_source(twointsclass &data)
{
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    twointsclass data;
    goodB2G_source(data);
    data.a = 1;
    data.b = 2;
    printIntLine(data.a);
    printIntLine(data.b);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_43; // so that we can use good and bad easily

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
