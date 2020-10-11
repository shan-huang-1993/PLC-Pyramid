/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_close_61b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

FILE * CWE404_Improper_Resource_Shutdown__freopen_close_61b_bad_source(FILE * data)
{
    data = freopen("BadSource_freopen.txt","w+",stdin);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
FILE * CWE404_Improper_Resource_Shutdown__freopen_close_61b_goodB2G_source(FILE * data)
{
    data = freopen("BadSource_freopen.txt","w+",stdin);
    return data;
}

#endif /* OMITGOOD */
