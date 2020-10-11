/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_68b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern FILE * CWE675_Duplicate_Operations_on_Resource__freopen_68_bad_data;
extern FILE * CWE675_Duplicate_Operations_on_Resource__freopen_68_goodG2B_data;
extern FILE * CWE675_Duplicate_Operations_on_Resource__freopen_68_goodB2G_data;

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__freopen_68b_bad_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_68_bad_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__freopen_68b_goodG2B_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_68_goodG2B_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__freopen_68b_goodB2G_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_68_goodB2G_data;
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */
