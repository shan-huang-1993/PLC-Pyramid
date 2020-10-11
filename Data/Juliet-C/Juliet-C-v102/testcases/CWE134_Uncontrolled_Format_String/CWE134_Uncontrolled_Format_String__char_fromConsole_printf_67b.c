/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67_struct_type;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_fromConsole_printf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* FIX: Specify the format disallowing a format string vulnerability */
    printf("%s\n", data);
}

#endif /* OMITGOOD */
