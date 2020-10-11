/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_18.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_18
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    twointsclass data_uninit_array[10];
    data = data_uninit_array;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
source:
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
sink:
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    twointsclass * data;
    twointsclass data_uninit_array[10];
    data = data_uninit_array;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
source:
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
sink:
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    twointsclass * data;
    twointsclass data_uninit_array[10];
    data = data_uninit_array;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
source:
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
sink:
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_18; // so that we can use good and bad easily

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
