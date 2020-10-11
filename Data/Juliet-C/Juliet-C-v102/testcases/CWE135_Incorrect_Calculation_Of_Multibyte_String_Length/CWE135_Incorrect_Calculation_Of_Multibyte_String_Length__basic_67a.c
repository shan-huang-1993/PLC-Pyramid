/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67a.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

typedef struct _CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type
{
    void * a;
} CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_bad_sink(CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct);

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_bad()
{
    void * data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    my_struct.a = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_goodG2B_sink(CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct);

static void goodG2B()
{
    void * data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct;
    data = NULL;
    /* FIX: Set data to point to a char string */
    data = CHAR_STRING;
    my_struct.a = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_goodB2G_sink(CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct);

static void goodB2G()
{
    void * data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_struct_type my_struct;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = WIDE_STRING;
    my_struct.a = data;
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67b_goodB2G_sink(my_struct);
}

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_good()
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
