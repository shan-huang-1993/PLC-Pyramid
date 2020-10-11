/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_wchar_t_61b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_wchar_t_61
{

#ifndef OMITBAD

wchar_t * bad_source(wchar_t * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new wchar_t;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * goodG2B_source(wchar_t * data)
{
    /* FIX: Use memory allocated on the stack */
    wchar_t data_good;
    data = &data_good;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
wchar_t * goodB2G_source(wchar_t * data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new wchar_t;
    /* Initialize and make use of data */
    *data = L'A';
    printHexCharLine((char)*data);
    return data;
}

#endif /* OMITGOOD */

} // close namespace
