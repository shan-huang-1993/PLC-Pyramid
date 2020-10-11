/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__large_char_52b.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks: char
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__large_char_52c_bad_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__large_char_52b_bad_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__large_char_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__large_char_52c_goodG2B_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__large_char_52b_goodG2B_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__large_char_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__large_char_52c_goodB2G_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__large_char_52b_goodB2G_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__large_char_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
