/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_61b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

twoints * CWE476_NULL_Pointer_Dereference__struct_61b_bad_source(twoints * data)
{
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twoints * CWE476_NULL_Pointer_Dereference__struct_61b_goodG2B_source(twoints * data)
{
    /* FIX: Initialize data - it will be used in the sink */
    {
        twoints tmp;
        tmp.a = 0;
        tmp.b = 0;
        data = &tmp;
    }
    return data;
}

#endif /* OMITGOOD */
