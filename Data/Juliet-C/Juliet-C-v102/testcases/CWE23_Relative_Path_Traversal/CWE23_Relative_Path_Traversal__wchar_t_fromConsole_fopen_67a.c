/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67a.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: File name without a period or slash
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type
{
    wchar_t * a;
} CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67b_bad_sink(CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type my_struct);

void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_bad()
{
    wchar_t * data;
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type my_struct;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(FILENAME_MAX-data_len > 1)
        {
            fgetws(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    my_struct.a = data;
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67b_goodG2B_sink(CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_struct_type my_struct;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    /* FIX: File name does not contain a period or slash */
    wcscat(data, L"file.txt");
    my_struct.a = data;
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67b_goodG2B_sink(my_struct);
}

void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
