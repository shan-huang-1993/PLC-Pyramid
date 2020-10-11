/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_fromFile_54d.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: fromFile Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_fromFile_54e_bad_sink(wchar_t * data);

void CWE114_Process_Control__w32_wchar_t_fromFile_54d_bad_sink(wchar_t * data)
{
    CWE114_Process_Control__w32_wchar_t_fromFile_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE114_Process_Control__w32_wchar_t_fromFile_54e_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_fromFile_54d_goodG2B_sink(wchar_t * data)
{
    CWE114_Process_Control__w32_wchar_t_fromFile_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
