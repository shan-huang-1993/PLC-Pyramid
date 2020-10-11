/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int_62b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_int_62
{

#ifndef OMITBAD

void bad_source(int * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(int * &data)
{
    /* FIX: Use memory allocated on the stack */
    int data_good;
    data = &data_good;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(int * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
}

#endif /* OMITGOOD */

} // close namespace
