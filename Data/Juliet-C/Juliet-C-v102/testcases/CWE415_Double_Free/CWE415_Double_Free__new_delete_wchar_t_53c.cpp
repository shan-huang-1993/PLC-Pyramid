/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_53c.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_wchar_t_53
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_d(wchar_t * data);

void bad_sink_c(wchar_t * data)
{
    bad_sink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(wchar_t * data);

void goodG2B_sink_c(wchar_t * data)
{
    goodG2B_sink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_d(wchar_t * data);

void goodB2G_sink_c(wchar_t * data)
{
    goodB2G_sink_d(data);
}

#endif /* OMITGOOD */

} // close namespace
