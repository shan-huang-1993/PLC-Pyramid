/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68a.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: fromConsole Read input from the console
 * GoodSource: Provide a matching password
 * Sinks: ncmp_user_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsncmp() to do password match, but use the length of the user password
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_bad_data;
wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_goodG2B_data;
wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_bad_sink();

void CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_bad_data = data;
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_goodG2B_sink();
void CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Use the matching string */
    data = PASSWORD;
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_goodG2B_data = data;
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_goodB2G_data = data;
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68b_goodB2G_sink();
}

void CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_good()
{
    goodG2B();
    goodB2G();
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
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__wchar_t_fromConsole_ncmp_user_pw_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
