/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsclass_61b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_twointsclass_61
{

#ifndef OMITBAD

twointsclass * bad_source(twointsclass * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printIntLine(data[0].a);
    printIntLine(data[0].b);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twointsclass * goodG2B_source(twointsclass * data)
{
    {
        /* FIX: Use memory allocated on the stack */
        twointsclass data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printIntLine(data[0].a);
        printIntLine(data[0].b);
    }
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
twointsclass * goodB2G_source(twointsclass * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printIntLine(data[0].a);
    printIntLine(data[0].b);
    return data;
}

#endif /* OMITGOOD */

} // close namespace
