/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_32.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_32_bad()
{
    void * data;
    void * *data_ptr1 = &data;
    void * *data_ptr2 = &data;
    data = NULL;
    {
        void * data = *data_ptr1;
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
        *data_ptr1 = data;
    }
    {
        void * data = *data_ptr2;
        {
            /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
            size_t data_len = strlen((char *)data);
            void * data_dest = (void *)calloc(data_len+1, 1);
            memcpy(data_dest, data, (data_len+1));
            printLine((char *)data_dest);
            free(data_dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    void * *data_ptr1 = &data;
    void * *data_ptr2 = &data;
    data = NULL;
    {
        void * data = *data_ptr1;
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
        *data_ptr1 = data;
    }
    {
        void * data = *data_ptr2;
        {
            /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
            size_t data_len = strlen((char *)data);
            void * data_dest = (void *)calloc(data_len+1, 1);
            memcpy(data_dest, data, (data_len+1));
            printLine((char *)data_dest);
            free(data_dest);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    void * data;
    void * *data_ptr1 = &data;
    void * *data_ptr2 = &data;
    data = NULL;
    {
        void * data = *data_ptr1;
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
        *data_ptr1 = data;
    }
    {
        void * data = *data_ptr2;
        {
            /* FIX - treating pointer like a wchar_t*  */
            size_t data_len = wcslen((wchar_t *)data);
            void * data_dest = (void *)calloc(data_len+1, sizeof(wchar_t));
            memcpy(data_dest, data, (data_len+1)*sizeof(wchar_t));
            printWLine((wchar_t *)data_dest);
            free(data_dest);
        }
    }
}

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_32_good()
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
