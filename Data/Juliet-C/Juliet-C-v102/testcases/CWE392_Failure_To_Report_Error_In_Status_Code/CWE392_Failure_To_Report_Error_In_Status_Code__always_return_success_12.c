/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE392_Failure_To_Report_Error_In_Status_Code__always_return_success_12.c
Label Definition File: CWE392_Failure_To_Report_Error_In_Status_Code.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 392 Failure to Report Error in Status Code
 * Sinks: always_return_success
 *    GoodSink: Return success when successful and fail when the function fails
 *    BadSink : Always return success
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

static int helper_bad()
{
    FILE *file;
    file = fopen("myfile.txt", "r+");
    /* FLAW: This function always returns true even if an error occurred */
    if (file == NULL) return 1;
    fclose(file);
    return 1;
}

static int helper_good()
{
    FILE *file;
    file = fopen("myfile.txt", "r+");
    /* FIX: Return true on success and false on failure */
    if (file == NULL) return 0;
    fclose(file);
    return 1;
}

#ifndef OMITBAD

void CWE392_Failure_To_Report_Error_In_Status_Code__always_return_success_12_bad()
{
    if(global_returns_t_or_f())
    {
        /* INCIDENTAL: Could trigger CWE571 - Expression is always true */
        if (helper_bad())
        {
            printLine("Success");
        }
        else
        {
            printLine("Failure");
        }
    }
    else
    {
        if (helper_good())
        {
            printLine("Success");
        }
        else
        {
            printLine("Failure");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        if (helper_good())
        {
            printLine("Success");
        }
        else
        {
            printLine("Failure");
        }
    }
    else
    {
        if (helper_good())
        {
            printLine("Success");
        }
        else
        {
            printLine("Failure");
        }
    }
}

void CWE392_Failure_To_Report_Error_In_Status_Code__always_return_success_12_good()
{
    good1();
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
    CWE392_Failure_To_Report_Error_In_Status_Code__always_return_success_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE392_Failure_To_Report_Error_In_Status_Code__always_return_success_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
