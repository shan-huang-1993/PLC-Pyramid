/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using strcpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

typedef struct _CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67_struct_type
{
    char * a;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67_struct_type;

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67b_bad_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        strcpy(data, data_src);
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67b_goodG2B_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__char_cpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        strcpy(data, data_src);
        printLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
