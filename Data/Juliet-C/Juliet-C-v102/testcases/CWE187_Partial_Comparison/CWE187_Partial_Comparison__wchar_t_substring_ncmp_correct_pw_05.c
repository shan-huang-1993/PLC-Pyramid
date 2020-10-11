/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_substring_ncmp_correct_pw_05.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: substring Provide a password that is a shortened version of the actual password
 * GoodSource: Provide a matching password
 * Sinks: ncmp_correct_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsncmp() to do password match, but use the length of the correct password
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE187_Partial_Comparison__wchar_t_substring_ncmp_correct_pw_05_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_t)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = L"P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(static_t)
    {
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_t to static_f */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_t)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = L"P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_t)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = L"P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(static_t)
    {
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_t to static_f */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = L"P";
    }
    else
    {
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(static_t)
    {
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_t)
    {
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = L"P";
    }
    if(static_t)
    {
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

void CWE187_Partial_Comparison__wchar_t_substring_ncmp_correct_pw_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE187_Partial_Comparison__wchar_t_substring_ncmp_correct_pw_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__wchar_t_substring_ncmp_correct_pw_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
