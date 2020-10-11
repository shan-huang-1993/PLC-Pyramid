/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_substring_str_67b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: substring Provide a password that is a shortened version of the actual password
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsstr() to do password match, which is a partial comparison
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

typedef struct _CWE187_Partial_Comparison__wchar_t_substring_str_67_struct_type
{
    wchar_t * a;
} CWE187_Partial_Comparison__wchar_t_substring_str_67_struct_type;

#ifndef OMITBAD

void CWE187_Partial_Comparison__wchar_t_substring_str_67b_bad_sink(CWE187_Partial_Comparison__wchar_t_substring_str_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (wcsstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__wchar_t_substring_str_67b_goodG2B_sink(CWE187_Partial_Comparison__wchar_t_substring_str_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (wcsstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__wchar_t_substring_str_67b_goodB2G_sink(CWE187_Partial_Comparison__wchar_t_substring_str_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* Ideally, we would want to do a check to see if the passwords are of equal length */
    /* FIX: Compare the two passwords completely and correctly */
    if (wcscmp(PASSWORD, data) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITGOOD */
