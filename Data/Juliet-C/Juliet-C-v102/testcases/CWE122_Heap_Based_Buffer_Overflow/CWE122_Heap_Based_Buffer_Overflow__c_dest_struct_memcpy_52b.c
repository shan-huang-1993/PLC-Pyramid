/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy twoints array to data using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52c_bad_sink(twoints * data);

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52b_bad_sink(twoints * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52c_goodG2B_sink(twoints * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52b_goodG2B_sink(twoints * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memcpy_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
