/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c_bad_sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b_bad_sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c_goodB2G_sink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52b_goodB2G_sink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
