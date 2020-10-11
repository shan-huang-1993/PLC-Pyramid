/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67a.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type
{
    int a;
} CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67b_bad_sink(CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type my_struct);

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_bad()
{
    int data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_struct.a = data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67b_goodG2B_sink(CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    my_struct.a = data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67b_goodG2B_sink(my_struct);
}

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_good()
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
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
