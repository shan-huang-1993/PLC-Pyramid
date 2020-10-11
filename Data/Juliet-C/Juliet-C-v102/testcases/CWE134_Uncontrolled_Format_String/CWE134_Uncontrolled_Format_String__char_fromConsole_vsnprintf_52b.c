/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vsnprintf
 *    GoodSink: vsnprintf with a format string
 *    BadSink : vsnprintf without a format string
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52b_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52b_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52b_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromConsole_vsnprintf_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
