/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54c.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromFile Read input from a file
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_bad_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54c_bad_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_goodG2B_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54c_goodG2B_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_goodB2G_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54c_goodB2G_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromFile_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
