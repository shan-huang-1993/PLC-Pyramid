/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53c_bad_sink(char * data);

void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53b_bad_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53b_goodG2B_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
