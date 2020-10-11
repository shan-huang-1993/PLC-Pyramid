/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_04.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_04_bad()
{
    void * data;
    data = NULL;
    if(static_const_t)
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* goodB2G1() - use badsource and goodsink by changing the second static_const_t to static_const_f */
static void goodB2G1()
{
    void * data;
    data = NULL;
    if(static_const_t)
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    void * data;
    data = NULL;
    if(static_const_t)
    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* goodG2B1() - use goodsource and badsink by changing the first static_const_t to static_const_f */
static void goodG2B1()
{
    void * data;
    data = NULL;
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    else
    {
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    void * data;
    data = NULL;
    if(static_const_t)
    {
        /* FIX: Set data to point to a char string */
        data = CHAR_STRING;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = WIDE_STRING;
    }
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
