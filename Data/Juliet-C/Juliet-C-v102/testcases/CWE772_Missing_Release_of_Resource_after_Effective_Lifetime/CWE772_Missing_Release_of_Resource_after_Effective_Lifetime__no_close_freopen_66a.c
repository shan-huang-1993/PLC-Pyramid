/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66a.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: freopen Open a file using freopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66b_bad_sink(FILE * data_array[]);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66_bad()
{
    FILE * data;
    FILE * data_array[5];
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* put data in array */
    data_array[2] = data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66b_goodB2G_sink(FILE * data_array[]);

static void goodB2G()
{
    FILE * data;
    FILE * data_array[5];
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    data_array[2] = data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66b_goodB2G_sink(data_array);
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
