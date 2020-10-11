/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67b.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67_struct_type
{
    void * a;
} CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67_struct_type;

#ifndef OMITBAD

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67b_bad_sink(CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67_struct_type my_struct)
{
    void * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67b_goodG2B_sink(CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_67_struct_type my_struct)
{
    void * data = my_struct.a;
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

#endif /* OMITGOOD */
