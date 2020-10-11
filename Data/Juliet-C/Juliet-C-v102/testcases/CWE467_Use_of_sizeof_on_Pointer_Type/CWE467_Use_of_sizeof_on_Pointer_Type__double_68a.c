/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__double_68a.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

double * CWE467_Use_of_sizeof_on_Pointer_Type__double_68_bad_data;
double * CWE467_Use_of_sizeof_on_Pointer_Type__double_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__double_68b_bad_sink();

void CWE467_Use_of_sizeof_on_Pointer_Type__double_68_bad()
{
    double * data;
    /* Initialize data */
    data = NULL;
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    *data = 1.7E300;
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68_bad_data = data;
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE467_Use_of_sizeof_on_Pointer_Type__double_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    double * data;
    /* Initialize data */
    data = NULL;
    /* FIX: Using sizeof the data type in malloc() */
    data = (double *)malloc(sizeof(*data));
    *data = 1.7E300;
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68_goodG2B_data = data;
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68b_goodG2B_sink();
}

void CWE467_Use_of_sizeof_on_Pointer_Type__double_68_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__double_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
