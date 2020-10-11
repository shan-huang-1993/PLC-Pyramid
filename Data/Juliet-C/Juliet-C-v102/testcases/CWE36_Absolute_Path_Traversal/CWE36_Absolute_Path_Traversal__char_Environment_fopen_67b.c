/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_Environment_fopen_67b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-67b.tmpl.c
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

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE36_Absolute_Path_Traversal__char_Environment_fopen_67_struct_type
{
    char * a;
} CWE36_Absolute_Path_Traversal__char_Environment_fopen_67_struct_type;

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__char_Environment_fopen_67b_bad_sink(CWE36_Absolute_Path_Traversal__char_Environment_fopen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, "wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_Environment_fopen_67b_goodG2B_sink(CWE36_Absolute_Path_Traversal__char_Environment_fopen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, "wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITGOOD */
