/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65a.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: freopen Open a file using freopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65b_bad_sink(FILE * data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65_bad()
{
    FILE * data;
    /* define a function pointer */
    void (*func_ptr) (FILE *) = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65b_bad_sink;
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65b_goodB2G_sink(FILE * data);

static void goodB2G()
{
    FILE * data;
    void (*func_ptr) (FILE *) = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65b_goodB2G_sink;
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    func_ptr(data);
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_freopen_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
