/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_12.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_12_bad()
{
    void * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
            size_t data_len = strlen((char *)data);
            void * data_dest = (void *)calloc(data_len+1, 1);
            memcpy(data_dest, data, (data_len+1));
            printLine((char *)data_dest);
            free(data_dest);
        }
    }
    else
    {
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    void * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    if(global_returns_t_or_f())
    {
        {
            /* FIX - treating pointer like a wchar_t*  */
            size_t data_len = wcslen((wchar_t *)data);
            void * data_dest = (void *)calloc(data_len+1, sizeof(wchar_t));
            memcpy(data_dest, data, (data_len+1)*sizeof(wchar_t));
            printWLine((wchar_t *)data_dest);
            free(data_dest);
        }
    }
    else
    {
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

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    void * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    else
    {
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
            size_t data_len = strlen((char *)data);
            void * data_dest = (void *)calloc(data_len+1, 1);
            memcpy(data_dest, data, (data_len+1));
            printLine((char *)data_dest);
            free(data_dest);
        }
    }
    else
    {
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

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_12_good()
{
    goodB2G();
    goodG2B();
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
