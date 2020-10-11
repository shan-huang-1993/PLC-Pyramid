/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__fopen_66a.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__fopen_66b_bad_sink(FILE * data_array[]);

void CWE690_NULL_Deref_from_Return__fopen_66_bad()
{
    FILE * data;
    FILE * data_array[5];
    /* Initialize data */
    data = NULL;
    data = fopen("file.txt", "w+");
    /* put data in array */
    data_array[2] = data;
    CWE690_NULL_Deref_from_Return__fopen_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__fopen_66b_goodB2G_sink(FILE * data_array[]);

static void goodB2G()
{
    FILE * data;
    FILE * data_array[5];
    /* Initialize data */
    data = NULL;
    data = fopen("file.txt", "w+");
    data_array[2] = data;
    CWE690_NULL_Deref_from_Return__fopen_66b_goodB2G_sink(data_array);
}

void CWE690_NULL_Deref_from_Return__fopen_66_good()
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
    CWE690_NULL_Deref_from_Return__fopen_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__fopen_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
