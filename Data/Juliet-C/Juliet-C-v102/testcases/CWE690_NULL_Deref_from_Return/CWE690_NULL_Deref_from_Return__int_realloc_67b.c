/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__int_realloc_67b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE690_NULL_Deref_from_Return__int_realloc_67_struct_type
{
    int * a;
} CWE690_NULL_Deref_from_Return__int_realloc_67_struct_type;

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__int_realloc_67b_bad_sink(CWE690_NULL_Deref_from_Return__int_realloc_67_struct_type my_struct)
{
    int * data = my_struct.a;
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5;
    printIntLine(data[0]);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__int_realloc_67b_goodB2G_sink(CWE690_NULL_Deref_from_Return__int_realloc_67_struct_type my_struct)
{
    int * data = my_struct.a;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITGOOD */
