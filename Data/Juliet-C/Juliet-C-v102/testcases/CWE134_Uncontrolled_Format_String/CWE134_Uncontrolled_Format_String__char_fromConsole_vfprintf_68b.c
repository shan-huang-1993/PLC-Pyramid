/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfprintf with a format string
 *    BadSink : vfprintf without a format string
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

extern char * CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_bad_data;
extern char * CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_goodG2B_data;
extern char * CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_goodB2G_data;

#ifndef OMITBAD

static void bad_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68b_bad_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_bad_data;
    bad_vasink(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68b_goodG2B_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_goodG2B_data;
    goodG2B_vasink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfprintf(stdout, "%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68b_goodB2G_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_fromConsole_vfprintf_68_goodB2G_data;
    goodB2G_vasink(data, data);
}

#endif /* OMITGOOD */
