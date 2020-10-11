/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int_67b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__int_67_struct_type
{
    int * a;
} CWE476_NULL_Pointer_Dereference__int_67_struct_type;

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__int_67b_bad_sink(CWE476_NULL_Pointer_Dereference__int_67_struct_type my_struct)
{
    int * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__int_67b_goodG2B_sink(CWE476_NULL_Pointer_Dereference__int_67_struct_type my_struct)
{
    int * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(*data);
}

#endif /* OMITGOOD */
