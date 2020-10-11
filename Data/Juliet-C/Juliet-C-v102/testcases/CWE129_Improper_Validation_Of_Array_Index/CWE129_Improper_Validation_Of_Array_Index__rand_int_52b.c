/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__rand_int_52b.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_bad_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__rand_int_52b_bad_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_goodG2B_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__rand_int_52b_goodG2B_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_goodB2G_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__rand_int_52b_goodB2G_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__rand_int_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
