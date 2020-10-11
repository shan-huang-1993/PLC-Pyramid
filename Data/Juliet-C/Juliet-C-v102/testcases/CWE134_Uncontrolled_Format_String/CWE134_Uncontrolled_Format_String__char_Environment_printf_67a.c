/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_Environment_printf_67a.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct);

void CWE134_Uncontrolled_Format_String__char_Environment_printf_67_bad()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct);

static void goodB2G()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67b_goodB2G_sink(my_struct);
}

void CWE134_Uncontrolled_Format_String__char_Environment_printf_67_good()
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
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_Environment_printf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
