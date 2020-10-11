/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_fscanf_61b.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks:
 *    BadSink : Divide a constant by data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

float CWE369_Divide_By_Zero__float_fscanf_61b_bad_source(float data)
{
    /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%f", &data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
float CWE369_Divide_By_Zero__float_fscanf_61b_goodG2B_source(float data)
{
    /* FIX: Use a value not equal to zero */
    data = 7.0F;
    return data;
}

#endif /* OMITGOOD */