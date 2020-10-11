/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_no_init_63b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
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

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_no_init_63
{

#ifndef OMITBAD

void bad_sink(twointsclass * * data_ptr)
{
    twointsclass * data = *data_ptr;
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(twointsclass * * data_ptr)
{
    twointsclass * data = *data_ptr;
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].a);
        printIntLine(data[i].b);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(twointsclass * * data_ptr)
{
    twointsclass * data = *data_ptr;
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

#endif /* OMITGOOD */

} // close namespace
