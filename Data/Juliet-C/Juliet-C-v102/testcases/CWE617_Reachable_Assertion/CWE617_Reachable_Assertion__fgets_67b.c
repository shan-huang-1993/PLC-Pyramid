/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fgets_67b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

typedef struct _CWE617_Reachable_Assertion__fgets_67_struct_type
{
    int a;
} CWE617_Reachable_Assertion__fgets_67_struct_type;

#ifndef OMITBAD

void CWE617_Reachable_Assertion__fgets_67b_bad_sink(CWE617_Reachable_Assertion__fgets_67_struct_type my_struct)
{
    int data = my_struct.a;
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fgets_67b_goodG2B_sink(CWE617_Reachable_Assertion__fgets_67_struct_type my_struct)
{
    int data = my_struct.a;
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITGOOD */
