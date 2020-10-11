/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68b.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68_bad_data_for_bad_sink;

extern HANDLE CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68_bad_data_for_good_sink;

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68b_bad_sink()
{
    HANDLE data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68_bad_data_for_bad_sink;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68b_goodB2G_sink()
{
    HANDLE data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_68_bad_data_for_good_sink;
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
