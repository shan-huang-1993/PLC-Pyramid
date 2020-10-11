/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_bad_sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_bad_sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_goodB2G_sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_goodB2G_sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
