/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_fscanf_67a.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks:
 *    BadSink : Divide a constant by data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE369_Divide_By_Zero__float_fscanf_67_struct_type
{
    float a;
} CWE369_Divide_By_Zero__float_fscanf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__float_fscanf_67b_bad_sink(CWE369_Divide_By_Zero__float_fscanf_67_struct_type my_struct);

void CWE369_Divide_By_Zero__float_fscanf_67_bad()
{
    float data;
    CWE369_Divide_By_Zero__float_fscanf_67_struct_type my_struct;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%f", &data);
    my_struct.a = data;
    CWE369_Divide_By_Zero__float_fscanf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__float_fscanf_67b_goodG2B_sink(CWE369_Divide_By_Zero__float_fscanf_67_struct_type my_struct);

static void goodG2B()
{
    float data;
    CWE369_Divide_By_Zero__float_fscanf_67_struct_type my_struct;
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a value not equal to zero */
    data = 7.0F;
    my_struct.a = data;
    CWE369_Divide_By_Zero__float_fscanf_67b_goodG2B_sink(my_struct);
}

void CWE369_Divide_By_Zero__float_fscanf_67_good()
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
    CWE369_Divide_By_Zero__float_fscanf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_fscanf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
