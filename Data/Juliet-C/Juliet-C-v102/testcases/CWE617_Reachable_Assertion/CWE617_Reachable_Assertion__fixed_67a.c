/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_67a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

typedef struct _CWE617_Reachable_Assertion__fixed_67_struct_type
{
    int a;
} CWE617_Reachable_Assertion__fixed_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fixed_67b_bad_sink(CWE617_Reachable_Assertion__fixed_67_struct_type my_struct);

void CWE617_Reachable_Assertion__fixed_67_bad()
{
    int data;
    CWE617_Reachable_Assertion__fixed_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value less than the assert value */
    data = ASSERT_VALUE-1;
    my_struct.a = data;
    CWE617_Reachable_Assertion__fixed_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fixed_67b_goodG2B_sink(CWE617_Reachable_Assertion__fixed_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE617_Reachable_Assertion__fixed_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    my_struct.a = data;
    CWE617_Reachable_Assertion__fixed_67b_goodG2B_sink(my_struct);
}

void CWE617_Reachable_Assertion__fixed_67_good()
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
    CWE617_Reachable_Assertion__fixed_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fixed_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
