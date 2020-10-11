/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_16.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: fromConsole Read input from the console
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH L"%SystemRoot%\\system32"
# define PUTENV _wputenv
#else
# define NEW_PATH L"/bin"
# define PUTENV wputenv
#endif

#ifndef OMITBAD

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_16_bad()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set the path as the "system" path */
        wcscat(data, NEW_PATH);
        break;
    }
    while(1)
    {
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(250-data_len > 1)
            {
                fgetws(data+data_len, (int)(250-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        break;
    }
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    while(1)
    {
        /* FIX: Set the path as the "system" path */
        wcscat(data, NEW_PATH);
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(250-data_len > 1)
            {
                fgetws(data+data_len, (int)(250-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        break;
    }
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_16_good()
{
    goodG2B();
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
