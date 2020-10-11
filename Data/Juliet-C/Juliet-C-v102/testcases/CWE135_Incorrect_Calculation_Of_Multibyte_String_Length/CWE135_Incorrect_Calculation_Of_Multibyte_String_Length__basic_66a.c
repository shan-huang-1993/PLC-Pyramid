/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66a.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

/* bad function declaration */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_bad_sink(void * data_array[]);

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66_bad()
{
    void * data;
    void * data_array[5];
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    /* put data in array */
    data_array[2] = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_goodG2B_sink(void * data_array[]);

static void goodG2B()
{
    void * data;
    void * data_array[5];
    data = NULL;
    /* FIX: Set data to point to a char string */
    data = CHAR_STRING;
    data_array[2] = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_goodG2B_sink(data_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_goodB2G_sink(void * data_array[]);

static void goodB2G()
{
    void * data;
    void * data_array[5];
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    data_array[2] = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66b_goodB2G_sink(data_array);
}

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66_good()
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif