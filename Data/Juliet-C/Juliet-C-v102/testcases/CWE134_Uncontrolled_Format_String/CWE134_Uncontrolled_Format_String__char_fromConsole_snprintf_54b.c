/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define SNPRINTF _snprintf
#else /* NOT _WIN32 */
# define SNPRINTF snprintf
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54b_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54b_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54b_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_snprintf_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
