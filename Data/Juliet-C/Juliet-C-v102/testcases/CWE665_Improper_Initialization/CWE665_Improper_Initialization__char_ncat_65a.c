/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_65a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE665_Improper_Initialization__char_ncat_65b_bad_sink(char * data);

void CWE665_Improper_Initialization__char_ncat_65_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = CWE665_Improper_Initialization__char_ncat_65b_bad_sink;
    char data_buf[100];
    data = data_buf;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__char_ncat_65b_goodG2B_sink(char * data);

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = CWE665_Improper_Initialization__char_ncat_65b_goodG2B_sink;
    char data_buf[100];
    data = data_buf;
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    func_ptr(data);
}

void CWE665_Improper_Initialization__char_ncat_65_good()
{
    goodG2B();
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
    CWE665_Improper_Initialization__char_ncat_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
