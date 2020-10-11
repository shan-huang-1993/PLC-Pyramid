/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type
{
    twoints * a;
} CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type;

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_bad_sink(CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct)
{
    twoints * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_goodG2B_sink(CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct)
{
    twoints * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

#endif /* OMITGOOD */
