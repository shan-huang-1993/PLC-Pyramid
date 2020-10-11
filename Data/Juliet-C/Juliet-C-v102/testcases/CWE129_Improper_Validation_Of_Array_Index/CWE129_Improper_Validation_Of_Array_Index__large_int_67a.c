/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__large_int_67a.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type
{
    int a;
} CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__large_int_67b_bad_sink(CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct);

void CWE129_Improper_Validation_Of_Array_Index__large_int_67_bad()
{
    int data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct;
    data = -1; /* Initialize data */
    /* FLAW: Use an invalid index */
    data = 10;
    my_struct.a = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__large_int_67b_goodG2B_sink(CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct;
    data = -1; /* Initialize data */
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    my_struct.a = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__large_int_67b_goodB2G_sink(CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct);

static void goodB2G()
{
    int data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67_struct_type my_struct;
    data = -1; /* Initialize data */
    /* FLAW: Use an invalid index */
    data = 10;
    my_struct.a = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_67b_goodB2G_sink(my_struct);
}

void CWE129_Improper_Validation_Of_Array_Index__large_int_67_good()
{
    goodG2B();
    goodB2G();
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
    CWE129_Improper_Validation_Of_Array_Index__large_int_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__large_int_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
