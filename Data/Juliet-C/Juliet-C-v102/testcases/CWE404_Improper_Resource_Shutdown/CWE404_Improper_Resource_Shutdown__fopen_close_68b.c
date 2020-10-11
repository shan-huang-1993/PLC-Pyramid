/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_close_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

extern FILE * CWE404_Improper_Resource_Shutdown__fopen_close_68_bad_data_for_bad_sink;

extern FILE * CWE404_Improper_Resource_Shutdown__fopen_close_68_bad_data_for_good_sink;

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__fopen_close_68b_bad_sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__fopen_close_68_bad_data_for_bad_sink;
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using close() instead of fclose() */
        CLOSE((int)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE404_Improper_Resource_Shutdown__fopen_close_68b_goodB2G_sink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__fopen_close_68_bad_data_for_good_sink;
    if (data != NULL)
    {
        /* FIX: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITGOOD */
