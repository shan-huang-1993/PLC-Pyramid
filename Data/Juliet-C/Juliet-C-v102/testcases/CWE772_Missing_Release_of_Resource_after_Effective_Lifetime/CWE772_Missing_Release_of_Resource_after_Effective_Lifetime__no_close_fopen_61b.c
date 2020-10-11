/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_61b.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

FILE * CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_61b_bad_source(FILE * data)
{
    data = fopen("BadSource_fopen.txt", "w+");
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
FILE * CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_61b_goodB2G_source(FILE * data)
{
    data = fopen("BadSource_fopen.txt", "w+");
    return data;
}

#endif /* OMITGOOD */
