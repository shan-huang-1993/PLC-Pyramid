/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__long_long_07.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-07.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_07_bad()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (long long *)malloc(sizeof(data));
        *data = 2147483643;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Using sizeof the data type in malloc() */
        data = (long long *)malloc(sizeof(*data));
        *data = 2147483643;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_five==5 to static_five!=5 */
static void goodG2B1()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (long long *)malloc(sizeof(data));
        *data = 2147483643;
    }
    else
    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (long long *)malloc(sizeof(*data));
        *data = 2147483643;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (long long *)malloc(sizeof(*data));
        *data = 2147483643;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (long long *)malloc(sizeof(data));
        *data = 2147483643;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_07_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE467_Use_of_sizeof_on_Pointer_Type__long_long_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__long_long_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
