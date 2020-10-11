/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_62b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_62
{

#ifndef OMITBAD

void bad_source(twointsclass * &data)
{
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(twointsclass * &data)
{
    {
        twointsclass * tmp = new twointsclass;
        tmp->a = 0;
        tmp->b = 0;
        /* FIX: Initialize data - it will be used in the sink */
        data = tmp;
    }
}

#endif /* OMITGOOD */

} // close namespace
