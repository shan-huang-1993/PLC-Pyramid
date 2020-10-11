/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_68b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE665_Improper_Initialization__char_ncat_68_bad_data;
extern char * CWE665_Improper_Initialization__char_ncat_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE665_Improper_Initialization__char_ncat_68b_bad_sink()
{
    char * data = CWE665_Improper_Initialization__char_ncat_68_bad_data;
    {
        size_t src_len;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        src_len = strlen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, src, src_len);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__char_ncat_68b_goodG2B_sink()
{
    char * data = CWE665_Improper_Initialization__char_ncat_68_goodG2B_data;
    {
        size_t src_len;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        src_len = strlen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, src, src_len);
        printLine(data);
    }
}

#endif /* OMITGOOD */
