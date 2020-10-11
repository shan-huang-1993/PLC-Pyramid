/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_61b.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_61b_bad_source(void * data)
{
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_61b_goodG2B_source(void * data)
{
    /* FIX: Set data to point to a char string */
    data = CHAR_STRING;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_61b_goodB2G_source(void * data)
{
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    return data;
}

#endif /* OMITGOOD */
