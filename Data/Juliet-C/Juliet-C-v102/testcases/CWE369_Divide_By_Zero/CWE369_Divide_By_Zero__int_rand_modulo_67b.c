/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_rand_modulo_67b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE369_Divide_By_Zero__int_rand_modulo_67_struct_type
{
    int a;
} CWE369_Divide_By_Zero__int_rand_modulo_67_struct_type;

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_rand_modulo_67b_bad_sink(CWE369_Divide_By_Zero__int_rand_modulo_67_struct_type my_struct)
{
    int data = my_struct.a;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_rand_modulo_67b_goodG2B_sink(CWE369_Divide_By_Zero__int_rand_modulo_67_struct_type my_struct)
{
    int data = my_struct.a;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITGOOD */
