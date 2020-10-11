/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_divide_61b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE369_Divide_By_Zero__int_fscanf_divide_61b_bad_source(int data)
{
    fscanf (stdin, "%d", &data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE369_Divide_By_Zero__int_fscanf_divide_61b_goodG2B_source(int data)
{
    /* FIX: Use a value not equal to zero */
    data = 7;
    return data;
}

#endif /* OMITGOOD */
