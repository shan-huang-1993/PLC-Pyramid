/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_fgets_67b.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sinks:
 *    BadSink : Divide a constant by data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

typedef struct _CWE369_Divide_By_Zero__float_fgets_67_struct_type
{
    float a;
} CWE369_Divide_By_Zero__float_fgets_67_struct_type;

#ifndef OMITBAD

void CWE369_Divide_By_Zero__float_fgets_67b_bad_sink(CWE369_Divide_By_Zero__float_fgets_67_struct_type my_struct)
{
    float data = my_struct.a;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__float_fgets_67b_goodG2B_sink(CWE369_Divide_By_Zero__float_fgets_67_struct_type my_struct)
{
    float data = my_struct.a;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

#endif /* OMITGOOD */
