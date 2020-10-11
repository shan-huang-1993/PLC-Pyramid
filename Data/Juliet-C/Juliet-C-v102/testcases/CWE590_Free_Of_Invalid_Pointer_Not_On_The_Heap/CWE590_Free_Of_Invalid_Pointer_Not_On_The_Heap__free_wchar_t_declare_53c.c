/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53c.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53d_bad_sink(wchar_t * data);

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53c_bad_sink(wchar_t * data)
{
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53d_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53c_goodG2B_sink(wchar_t * data)
{
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
