/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE392_Failure_To_Report_Error_In_Status_Code__fail_to_set_error_code_04.c
Label Definition File: CWE392_Failure_To_Report_Error_In_Status_Code.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 392 Failure to Report Error in Status Code
 * Sinks: fail_to_set_error_code
 *    GoodSink: Properly set the error code when an error occurs
 *    BadSink : Fail to set the error code when an error occurs
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

enum
{
    E_OK = 0,
    E_FILE_NOT_OPENED = 1,
    E_OTHER = 2
};

#define INPUT_SZ 10

static int helper_bad(int *error_code)
{
    FILE *file;
    *error_code = E_OK;
    file = fopen("myfile.txt", "r+");
    /* FLAW: This function returns failure, but does not set the error code appropiately */
    if (file == NULL) return 0;
    fclose(file);
    return 1;
}

static int helper_good(int *error_code)
{
    FILE *file;
    *error_code = E_OK;
    file = fopen("myfile.txt", "r+");
    /* FIX: Set the error code properly when returning failure */
    if (file == NULL)
    {
        *error_code = E_FILE_NOT_OPENED;
        return 0;
    }
    fclose(file);
    return 1;
}

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE392_Failure_To_Report_Error_In_Status_Code__fail_to_set_error_code_04_bad()
{
    if(static_const_t)
    {
        {
            int error_code;
            if (helper_bad(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int error_code;
            if (helper_good(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int error_code;
            if (helper_bad(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
    else
    {
        {
            int error_code;
            if (helper_good(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            int error_code;
            if (helper_good(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int error_code;
            if (helper_bad(&error_code))
            {
                printLine("Success");
            }
            else
            {
                printLine("Failure");
            }
            if (error_code == E_OK)
            {
                printLine("Other success");
            }
        }
    }
}

void CWE392_Failure_To_Report_Error_In_Status_Code__fail_to_set_error_code_04_good()
{
    good1();
    good2();
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
    CWE392_Failure_To_Report_Error_In_Status_Code__fail_to_set_error_code_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE392_Failure_To_Report_Error_In_Status_Code__fail_to_set_error_code_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
