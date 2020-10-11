/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH L"%SystemRoot%\\system32"
# define PUTENV _wputenv
#else
# define NEW_PATH L"/bin"
# define PUTENV wputenv
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

typedef struct _CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type
{
    wchar_t * a;
} CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67b_bad_sink(CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type my_struct);

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_bad()
{
    wchar_t * data;
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type my_struct;
    wchar_t data_buf[250] = L"PATH=";
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67b_goodG2B_sink(CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_struct_type my_struct;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    /* FIX: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
    my_struct.a = data;
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67b_goodG2B_sink(my_struct);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_good()
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
