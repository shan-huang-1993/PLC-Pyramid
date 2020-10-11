/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_loop_67b.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE126_Buffer_Overread__malloc_char_loop_67_struct_type
{
    char * a;
} CWE126_Buffer_Overread__malloc_char_loop_67_struct_type;

#ifndef OMITBAD

void CWE126_Buffer_Overread__malloc_char_loop_67b_bad_sink(CWE126_Buffer_Overread__malloc_char_loop_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        size_t i, dest_sz;
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        dest_sz = strlen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < dest_sz; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = '\0';
        printLine(dest);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__malloc_char_loop_67b_goodG2B_sink(CWE126_Buffer_Overread__malloc_char_loop_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        size_t i, dest_sz;
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        dest_sz = strlen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < dest_sz; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = '\0';
        printLine(dest);
        free(data);
    }
}

#endif /* OMITGOOD */
