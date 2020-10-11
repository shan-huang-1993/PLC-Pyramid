/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define SNPRINTF _snprintf
#else /* NOT _WIN32 */
# define SNPRINTF snprintf
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67_struct_type;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[100] = "";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}

#endif /* OMITGOOD */
