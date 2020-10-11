/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67a.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type
{
    char * a;
} CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67b_bad_sink(CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type my_struct);

void CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_bad()
{
    char * data;
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type my_struct;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(FILENAME_MAX-data_len > 1)
        {
            fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    my_struct.a = data;
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67b_goodG2B_sink(CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_struct_type my_struct;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    strcpy(data, "c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    strcpy(data, "/tmp/file.txt");
#endif
    my_struct.a = data;
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67b_goodG2B_sink(my_struct);
}

void CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_good()
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
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_fromConsole_fopen_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
