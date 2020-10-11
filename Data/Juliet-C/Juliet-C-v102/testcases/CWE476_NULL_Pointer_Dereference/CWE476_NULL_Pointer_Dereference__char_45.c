/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_45.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static char * CWE476_NULL_Pointer_Dereference__char_45_bad_data;
static char * CWE476_NULL_Pointer_Dereference__char_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_45_bad_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printf("%s\n", data);
}

void CWE476_NULL_Pointer_Dereference__char_45_bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    char * data = CWE476_NULL_Pointer_Dereference__char_45_goodG2B_data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printf("%s\n", data);
}

static void goodG2B()
{
    char * data;
    /* Initialize data */
    data = NULL;
    /* FIX: Initialize data - it will be used in the sink */
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE476_NULL_Pointer_Dereference__char_45_good()
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
    CWE476_NULL_Pointer_Dereference__char_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__char_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
