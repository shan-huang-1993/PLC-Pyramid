/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67b.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sinks: execl
 *    BadSink : execute command with wexecl
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT L"cmd.exe"
# define COMMAND_ARG1 L"/c"
# define COMMAND_ARG2 L"dir"
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT_PATH L"/bin/sh"
# define COMMAND_INT L"sh"
# define COMMAND_ARG1 L"ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
#include <process.h>
# define EXECL _wexecl
#else /* NOT _WIN32 */
# define EXECL wexecl
#endif

typedef struct _CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67_struct_type
{
    wchar_t * a;
} CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67_struct_type;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67b_bad_sink(CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* wexecl - specify the path where the command is located */
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    EXECL(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67b_goodG2B_sink(CWE78_OS_Command_Injection__wchar_t_fromFile_execl_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* wexecl - specify the path where the command is located */
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    EXECL(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

#endif /* OMITGOOD */
