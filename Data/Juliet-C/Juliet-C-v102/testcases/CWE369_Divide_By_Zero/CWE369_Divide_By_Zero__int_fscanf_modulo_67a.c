/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_modulo_67a.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type
{
    int a;
} CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fscanf_modulo_67b_bad_sink(CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type my_struct);

void CWE369_Divide_By_Zero__int_fscanf_modulo_67_bad()
{
    int data;
    CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_struct.a = data;
    CWE369_Divide_By_Zero__int_fscanf_modulo_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fscanf_modulo_67b_goodG2B_sink(CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE369_Divide_By_Zero__int_fscanf_modulo_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    my_struct.a = data;
    CWE369_Divide_By_Zero__int_fscanf_modulo_67b_goodG2B_sink(my_struct);
}

void CWE369_Divide_By_Zero__int_fscanf_modulo_67_good()
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
    CWE369_Divide_By_Zero__int_fscanf_modulo_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_fscanf_modulo_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
