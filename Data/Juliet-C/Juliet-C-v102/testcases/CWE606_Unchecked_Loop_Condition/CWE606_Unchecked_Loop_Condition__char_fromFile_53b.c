/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_fromFile_53b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromFile Read input from a file
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__char_fromFile_53c_bad_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_fromFile_53b_bad_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_fromFile_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__char_fromFile_53c_goodG2B_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_fromFile_53b_goodG2B_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_fromFile_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__char_fromFile_53c_goodB2G_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_fromFile_53b_goodB2G_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_fromFile_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
