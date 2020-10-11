/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fixed_add_67b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__int_fixed_add_67_struct_type
{
    int a;
} CWE190_Integer_Overflow__int_fixed_add_67_struct_type;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fixed_add_67b_bad_sink(CWE190_Integer_Overflow__int_fixed_add_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an integer overflow */
        int result = data + 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fixed_add_67b_goodG2B_sink(CWE190_Integer_Overflow__int_fixed_add_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an integer overflow */
        int result = data + 1;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fixed_add_67b_goodB2G_sink(CWE190_Integer_Overflow__int_fixed_add_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < INT_MAX)
        {
            result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
