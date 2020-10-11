/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_wchar_t_62b.cpp
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

namespace CWE401_Memory_Leak__new_array_wchar_t_62
{

#ifndef OMITBAD

void bad_source(wchar_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new wchar_t[100];
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(wchar_t * &data)
{
    {
        /* FIX: Use memory allocated on the stack */
        wchar_t data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(wchar_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new wchar_t[100];
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
}

#endif /* OMITGOOD */

} // close namespace
