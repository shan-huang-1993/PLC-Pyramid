/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54a.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close.label.xml
Template File: source-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54b_bad_sink(HANDLE data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54b_goodB2G_sink(HANDLE data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54b_goodB2G_sink(data);
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54_good()
{
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif