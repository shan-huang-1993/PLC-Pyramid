/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67b.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks: wchar_t
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67_struct_type
{
    int a;
} CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67_struct_type;

#ifndef OMITBAD

void CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67b_bad_sink(CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67b_goodG2B_sink(CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67b_goodB2G_sink(CWE129_Improper_Validation_Of_Array_Index__large_wchar_t_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* FIX: Properly validate the array index */
        if (data >= 0 && data < (10-1))  /* Include the -1 because we don't want to print null */
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

#endif /* OMITGOOD */
