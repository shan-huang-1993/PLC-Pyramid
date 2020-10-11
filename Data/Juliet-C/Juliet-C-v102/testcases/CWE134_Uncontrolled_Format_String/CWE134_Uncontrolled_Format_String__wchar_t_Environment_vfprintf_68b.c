/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_bad_data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_goodG2B_data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_goodB2G_data;

#ifndef OMITBAD

static void bad_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68b_bad_sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_bad_data;
    bad_vasink(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68b_goodG2B_sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_goodG2B_data;
    goodG2B_vasink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68b_goodB2G_sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_68_goodB2G_data;
    goodB2G_vasink(data, data);
}

#endif /* OMITGOOD */
