/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snwprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snwprintf with data as the third argument
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
# define SNPRINTF _snwprintf
#else /* NOT _WIN32 */
# define SNPRINTF snwprintf
#endif

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67_struct_type
{
    wchar_t * a;
} CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67_struct_type;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t dest[100] = L"";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__wchar_t_Environment_snprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t dest[100] = L"";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, L"%s", data);
        printWLine(dest);
    }
}

#endif /* OMITGOOD */
