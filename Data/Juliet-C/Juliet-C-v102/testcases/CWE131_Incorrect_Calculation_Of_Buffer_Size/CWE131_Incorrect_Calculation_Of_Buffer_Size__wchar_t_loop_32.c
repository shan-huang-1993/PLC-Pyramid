/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_32.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    data = NULL;
    {
        wchar_t * data = *data_ptr1;
        /* FLAW: Did not leave space for a null terminator */
        data = (wchar_t *)malloc(10*sizeof(wchar_t));
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            wchar_t data_src[10+1] = SRC_STRING;
            size_t i, src_len;
            src_len = wcslen(data_src);
            /* POTENTIAL FLAW: data may not have enough space to hold data_src */
            for (i = 0; i < src_len; i++)
            {
                data[i] = data_src[i];
            }
            data[wcslen(data_src)] = L'\0'; /* NULL terminate */
            printWLine(data);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    data = NULL;
    {
        wchar_t * data = *data_ptr1;
        /* FIX: Allocate space for a null terminator */
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            wchar_t data_src[10+1] = SRC_STRING;
            size_t i, src_len;
            src_len = wcslen(data_src);
            /* POTENTIAL FLAW: data may not have enough space to hold data_src */
            for (i = 0; i < src_len; i++)
            {
                data[i] = data_src[i];
            }
            data[wcslen(data_src)] = L'\0'; /* NULL terminate */
            printWLine(data);
            free(data);
        }
    }
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_32_good()
{
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
