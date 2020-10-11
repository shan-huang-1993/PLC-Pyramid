/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67_struct_type
{
    int * a;
} CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67_struct_type;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67b_bad_sink(CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67b_goodG2B_sink(CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memmove_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

#endif /* OMITGOOD */
