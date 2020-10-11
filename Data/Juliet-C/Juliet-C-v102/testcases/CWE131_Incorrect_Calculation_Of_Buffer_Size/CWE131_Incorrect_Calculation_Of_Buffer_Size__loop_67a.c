/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type
{
    int * a;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_bad_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_bad()
{
    int * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int *) */
    data = (int *)malloc(10);
    my_struct.a = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_goodG2B_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct);

static void goodG2B()
{
    int * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int *) */
    data = (int *)malloc(10*sizeof(int));
    my_struct.a = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_goodG2B_sink(my_struct);
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
