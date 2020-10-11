/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_45.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static twoints * CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_bad_data;
static twoints * CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    twoints * data = CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_bad_data;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (twoints *)malloc(sizeof(data));
    data->a = 1;
    data->b = 2;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    twoints * data = CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_goodG2B_data;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    /* FIX: Using sizeof the data type in malloc() */
    data = (twoints *)malloc(sizeof(*data));
    data->a = 1;
    data->b = 2;
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
