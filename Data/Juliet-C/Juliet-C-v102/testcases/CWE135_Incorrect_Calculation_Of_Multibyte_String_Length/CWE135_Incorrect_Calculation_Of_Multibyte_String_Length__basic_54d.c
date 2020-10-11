/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54d.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

/* bad function declaration */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_bad_sink(void * data);

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54d_bad_sink(void * data)
{
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_goodG2B_sink(void * data);

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54d_goodG2B_sink(void * data)
{
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_goodB2G_sink(void * data);

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54d_goodB2G_sink(void * data)
{
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
