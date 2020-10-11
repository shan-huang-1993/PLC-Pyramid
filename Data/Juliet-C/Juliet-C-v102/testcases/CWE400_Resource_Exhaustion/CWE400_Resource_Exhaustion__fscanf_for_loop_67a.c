/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_67a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type
{
    int a;
} CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fscanf_for_loop_67b_bad_sink(CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct);

void CWE400_Resource_Exhaustion__fscanf_for_loop_67_bad()
{
    int count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    fscanf (stdin, "%d", &count);
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fscanf_for_loop_67b_goodG2B_sink(CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct);

static void goodG2B()
{
    int count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fscanf_for_loop_67b_goodB2G_sink(CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct);

static void goodB2G()
{
    int count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    fscanf (stdin, "%d", &count);
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67b_goodB2G_sink(my_struct);
}

void CWE400_Resource_Exhaustion__fscanf_for_loop_67_good()
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
