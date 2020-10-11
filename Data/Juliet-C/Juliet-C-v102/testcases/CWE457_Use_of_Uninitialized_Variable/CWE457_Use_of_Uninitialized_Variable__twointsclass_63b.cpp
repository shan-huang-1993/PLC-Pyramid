/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_63b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_63
{

#ifndef OMITBAD

void bad_sink(twointsclass * data_ptr)
{
    twointsclass data = *data_ptr;
    printIntLine(data.a);
    printIntLine(data.b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(twointsclass * data_ptr)
{
    twointsclass data = *data_ptr;
    printIntLine(data.a);
    printIntLine(data.b);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(twointsclass * data_ptr)
{
    twointsclass data = *data_ptr;
    data.a = 1;
    data.b = 2;
    printIntLine(data.a);
    printIntLine(data.b);
}

#endif /* OMITGOOD */

} // close namespace
