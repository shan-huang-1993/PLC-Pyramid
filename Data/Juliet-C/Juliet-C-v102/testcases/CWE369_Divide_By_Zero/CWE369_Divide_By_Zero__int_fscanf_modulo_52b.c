/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_modulo_52b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fscanf_modulo_52c_bad_sink(int data);

void CWE369_Divide_By_Zero__int_fscanf_modulo_52b_bad_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_modulo_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_fscanf_modulo_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fscanf_modulo_52b_goodG2B_sink(int data)
{
    CWE369_Divide_By_Zero__int_fscanf_modulo_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
