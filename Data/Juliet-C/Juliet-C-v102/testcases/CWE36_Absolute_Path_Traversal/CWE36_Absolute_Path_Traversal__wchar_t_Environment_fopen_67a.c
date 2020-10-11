/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67a.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type
{
    wchar_t * a;
} CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67b_bad_sink(CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type my_struct);

void CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_bad()
{
    wchar_t * data;
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type my_struct;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_struct.a = data;
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67b_goodG2B_sink(CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_struct_type my_struct;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    wcscpy(data, L"c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    wcscpy(data, L"/tmp/file.txt");
#endif
    my_struct.a = data;
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67b_goodG2B_sink(my_struct);
}

void CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_good()
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
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_fopen_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
