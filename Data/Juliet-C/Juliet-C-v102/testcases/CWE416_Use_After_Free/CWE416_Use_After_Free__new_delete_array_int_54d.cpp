/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_int_54d.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_int_54
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_e(int * data);

void bad_sink_d(int * data)
{
    bad_sink_e(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_e(int * data);

void goodG2B_sink_d(int * data)
{
    goodG2B_sink_e(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_e(int * data);

void goodB2G_sink_d(int * data)
{
    goodB2G_sink_e(data);
}

#endif /* OMITGOOD */

} // close namespace
