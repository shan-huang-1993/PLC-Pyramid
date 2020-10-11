/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromConsole_system_67b.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromConsole Read input from the console
 * GoodSource: Benign input
 * Sinks: system
 *    BadSink : Execute command using system()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT "cmd.exe"
# define COMMAND_ARG1 "/c"
# define COMMAND_ARG2 "dir"
# define FULL_COMMAND COMMAND_INT_PATH " " COMMAND_ARG1 " "COMMAND_ARG2 " "
#else /* NOT _WIN32 */
# define COMMAND_INT_PATH "/bin/sh"
# define COMMAND_INT "sh"
# define COMMAND_ARG1 "ls"
# define FULL_COMMAND COMMAND_INT_PATH " " COMMAND_ARG1 " "
#endif

typedef struct _CWE78_OS_Command_Injection__char_fromConsole_system_67_struct_type
{
    char * a;
} CWE78_OS_Command_Injection__char_fromConsole_system_67_struct_type;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__char_fromConsole_system_67b_bad_sink(CWE78_OS_Command_Injection__char_fromConsole_system_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    system(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_fromConsole_system_67b_goodG2B_sink(CWE78_OS_Command_Injection__char_fromConsole_system_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    system(data);
}

#endif /* OMITGOOD */
