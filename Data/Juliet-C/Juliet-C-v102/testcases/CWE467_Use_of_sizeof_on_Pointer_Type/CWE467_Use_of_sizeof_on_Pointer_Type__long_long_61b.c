/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__long_long_61b.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

long long * CWE467_Use_of_sizeof_on_Pointer_Type__long_long_61b_bad_source(long long * data)
{
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (long long *)malloc(sizeof(data));
    *data = 2147483643;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
long long * CWE467_Use_of_sizeof_on_Pointer_Type__long_long_61b_goodG2B_source(long long * data)
{
    /* FIX: Using sizeof the data type in malloc() */
    data = (long long *)malloc(sizeof(*data));
    *data = 2147483643;
    return data;
}

#endif /* OMITGOOD */
