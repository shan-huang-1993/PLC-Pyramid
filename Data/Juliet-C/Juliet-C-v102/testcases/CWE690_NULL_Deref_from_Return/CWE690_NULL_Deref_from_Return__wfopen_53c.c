/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_53c.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define WFOPEN _wfopen
#else
/*fopen is used on unix-based OSs */
# define WFOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__wfopen_53d_bad_sink(FILE * data);

void CWE690_NULL_Deref_from_Return__wfopen_53c_bad_sink(FILE * data)
{
    CWE690_NULL_Deref_from_Return__wfopen_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__wfopen_53d_goodB2G_sink(FILE * data);

void CWE690_NULL_Deref_from_Return__wfopen_53c_goodB2G_sink(FILE * data)
{
    CWE690_NULL_Deref_from_Return__wfopen_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
