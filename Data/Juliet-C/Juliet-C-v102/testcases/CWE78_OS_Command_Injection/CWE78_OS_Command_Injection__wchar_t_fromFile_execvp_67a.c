/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67a.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sinks: execvp
 *    BadSink : execute command with wexecvp
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
# define EXECVP _wexecvp
#else /* NOT _WIN32 */
# define EXECVP wexecvp
#endif

typedef struct _CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type
{
    wchar_t * a;
} CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67b_bad_sink(CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type my_struct);

void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_bad()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_struct.a = data;
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67b_goodG2B_sink(CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    wcscat(data, L"*.*");
    my_struct.a = data;
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67b_goodG2B_sink(my_struct);
}

void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
