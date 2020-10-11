/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_long_long_62b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_long_long_62
{

#ifndef OMITBAD

void bad_source(long long * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new long long[100];
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(long long * &data)
{
    {
        /* FIX: Use memory allocated on the stack */
        long long data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0] = 5L;
        printLongLongLine(data[0]);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(long long * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new long long[100];
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
}

#endif /* OMITGOOD */

} // close namespace
