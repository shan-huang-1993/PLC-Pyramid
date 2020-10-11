/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53c.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memcpy
 *    BadSink : Copy int array to data using memcpy
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53d_bad_sink(int * data);

void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53c_bad_sink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53d_goodG2B_sink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53c_goodG2B_sink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_int_declare_memcpy_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
