/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_32.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_32_bad()
{
    twoints * data;
    twoints * *data_ptr1 = &data;
    twoints * *data_ptr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        twoints * data = *data_ptr1;
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (twoints *)malloc(sizeof(data));
        data->a = 1;
        data->b = 2;
        *data_ptr1 = data;
    }
    {
        twoints * data = *data_ptr2;
        /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
        printStructLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoints * data;
    twoints * *data_ptr1 = &data;
    twoints * *data_ptr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        twoints * data = *data_ptr1;
        /* FIX: Using sizeof the data type in malloc() */
        data = (twoints *)malloc(sizeof(*data));
        data->a = 1;
        data->b = 2;
        *data_ptr1 = data;
    }
    {
        twoints * data = *data_ptr2;
        /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
        printStructLine(data);
        free(data);
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_32_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
