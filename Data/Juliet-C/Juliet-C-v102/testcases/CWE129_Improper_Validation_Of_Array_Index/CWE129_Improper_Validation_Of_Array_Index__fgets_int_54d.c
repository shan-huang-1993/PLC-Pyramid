/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__fgets_int_54d.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_bad_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54d_bad_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_goodG2B_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54d_goodG2B_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_goodB2G_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__fgets_int_54d_goodB2G_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__fgets_int_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
