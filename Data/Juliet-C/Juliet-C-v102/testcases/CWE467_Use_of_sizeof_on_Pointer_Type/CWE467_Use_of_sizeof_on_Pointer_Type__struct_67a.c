/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_67a.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-67a.tmpl.c
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

/* bad function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_bad_sink(CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct);

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_bad()
{
    twoints * data;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (twoints *)malloc(sizeof(data));
    data->a = 1;
    data->b = 2;
    my_struct.a = data;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_goodG2B_sink(CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct);

static void goodG2B()
{
    twoints * data;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    /* FIX: Using sizeof the data type in malloc() */
    data = (twoints *)malloc(sizeof(*data));
    data->a = 1;
    data->b = 2;
    my_struct.a = data;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67b_goodG2B_sink(my_struct);
}

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
