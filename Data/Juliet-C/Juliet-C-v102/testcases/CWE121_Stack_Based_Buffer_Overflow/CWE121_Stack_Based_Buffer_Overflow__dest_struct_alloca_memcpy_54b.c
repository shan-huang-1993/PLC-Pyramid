/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memcpy
 *    BadSink : Copy twoints array to data using memcpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54c_bad_sink(twoints * data);

void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54b_bad_sink(twoints * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54c_goodG2B_sink(twoints * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54b_goodG2B_sink(twoints * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memcpy_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
