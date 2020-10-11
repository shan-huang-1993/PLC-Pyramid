/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67_struct_type
{
    int a;
} CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67_struct_type;

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67b_bad_sink(CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67b_goodG2B_sink(CWE197_Numeric_Truncation_Error__int_fscanf_to_char_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITGOOD */
