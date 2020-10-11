/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_wchar_t_61b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_wchar_t_61
{

#ifndef OMITBAD

wchar_t * bad_source(wchar_t * data)
{
    data = new wchar_t;
    *data = L'A';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * goodG2B_source(wchar_t * data)
{
    data = new wchar_t;
    *data = L'A';
    /* FIX: Do not delete data in the source */
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
wchar_t * goodB2G_source(wchar_t * data)
{
    data = new wchar_t;
    *data = L'A';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    return data;
}

#endif /* OMITGOOD */

} // close namespace
