/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_multiply_67a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type
{
    int a;
} CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int_fscanf_multiply_67b_bad_sink(CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct);

void CWE190_Integer_Overflow__int_fscanf_multiply_67_bad()
{
    int data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_struct.a = data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fscanf_multiply_67b_goodG2B_sink(CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 5;
    my_struct.a = data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fscanf_multiply_67b_goodB2G_sink(CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct);

static void goodB2G()
{
    int data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_struct.a = data;
    CWE190_Integer_Overflow__int_fscanf_multiply_67b_goodB2G_sink(my_struct);
}

void CWE190_Integer_Overflow__int_fscanf_multiply_67_good()
{
    goodG2B();
    goodB2G();
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
    CWE190_Integer_Overflow__int_fscanf_multiply_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fscanf_multiply_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
