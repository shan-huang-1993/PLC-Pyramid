/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68a.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad_data;
void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodG2B_data;
void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_bad_sink();

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad()
{
    void * data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad_data = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodG2B_sink();
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    data = NULL;
    /* FIX: Set data to point to a char string */
    data = CHAR_STRING;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodG2B_data = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    void * data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodB2G_data = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodB2G_sink();
}

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_good()
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
