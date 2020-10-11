/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cat
 *    BadSink : Copy data to string using strcat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67_struct_type
{
    char * a;
} CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67_struct_type;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67b_bad_sink(CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strcat(dest, data);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67b_goodG2B_sink(CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strcat(dest, data);
        printLine(data);
    }
}

#endif /* OMITGOOD */
