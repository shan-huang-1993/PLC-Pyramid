/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fgets_modulo_68b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

extern int CWE369_Divide_By_Zero__int_fgets_modulo_68_bad_data;
extern int CWE369_Divide_By_Zero__int_fgets_modulo_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_fgets_modulo_68b_bad_sink()
{
    int data = CWE369_Divide_By_Zero__int_fgets_modulo_68_bad_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fgets_modulo_68b_goodG2B_sink()
{
    int data = CWE369_Divide_By_Zero__int_fgets_modulo_68_goodG2B_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITGOOD */
