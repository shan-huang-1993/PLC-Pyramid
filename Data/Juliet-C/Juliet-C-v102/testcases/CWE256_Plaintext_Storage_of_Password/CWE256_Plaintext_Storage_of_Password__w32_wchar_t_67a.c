/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67a.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

typedef struct _CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type
{
    wchar_t * a;
} CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_bad_sink(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct);

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_bad()
{
    wchar_t * password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct;
    wchar_t password_buf[100] = L"";
    password = password_buf;
    {
        FILE *password_file;
        password_file = fopen("passwords.txt", "r");
        /* FLAW: Read the password from a file */
        fgetws(password, 100, password_file);
        fclose(password_file);
    }
    my_struct.a = password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_goodG2B_sink(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct;
    wchar_t password_buf[100] = L"";
    password = password_buf;
    {
        size_t password_len = 0;
        /* FIX: Read the password from the console */
        fgetws(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgetws() */
        password_len = wcslen(password);
        if (password_len > 0)
        {
            password[password_len-1] = L'\0';
        }
    }
    my_struct.a = password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_goodG2B_sink(my_struct);
}

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_good()
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
