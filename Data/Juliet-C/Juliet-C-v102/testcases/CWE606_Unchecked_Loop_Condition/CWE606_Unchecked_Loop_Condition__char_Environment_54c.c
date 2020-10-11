/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_Environment_54c.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__char_Environment_54d_bad_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_Environment_54c_bad_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_Environment_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__char_Environment_54d_goodG2B_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_Environment_54c_goodG2B_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_Environment_54d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__char_Environment_54d_goodB2G_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_Environment_54c_goodB2G_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_Environment_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
