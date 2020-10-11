/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65b_bad_sink(int * data);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65_bad()
{
    int * data;
    /* define a function pointer */
    void (*func_ptr) (int *) = CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65b_bad_sink;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int *) */
    data = (int *)malloc(10);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65b_goodG2B_sink(int * data);

static void goodG2B()
{
    int * data;
    void (*func_ptr) (int *) = CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65b_goodG2B_sink;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int *) */
    data = (int *)malloc(10*sizeof(int));
    func_ptr(data);
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
