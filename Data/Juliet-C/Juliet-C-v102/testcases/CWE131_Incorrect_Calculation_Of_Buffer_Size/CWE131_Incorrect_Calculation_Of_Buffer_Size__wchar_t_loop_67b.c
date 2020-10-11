/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67_struct_type
{
    wchar_t * a;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67_struct_type;

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67b_bad_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67b_goodG2B_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_loop_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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

#endif /* OMITGOOD */
