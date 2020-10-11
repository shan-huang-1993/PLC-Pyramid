/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67_struct_type;

#ifndef OMITBAD

static void bad_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
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
        vprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    goodG2B_vasink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vprintf("%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_Environment_vprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    goodB2G_vasink(data, data);
}

#endif /* OMITGOOD */
