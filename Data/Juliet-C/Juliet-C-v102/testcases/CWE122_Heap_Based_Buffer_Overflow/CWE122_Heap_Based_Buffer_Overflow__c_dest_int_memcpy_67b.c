/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy int array to data using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67_struct_type
{
    int * a;
} CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67_struct_type;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67b_bad_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67b_goodG2B_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_int_memcpy_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITGOOD */
