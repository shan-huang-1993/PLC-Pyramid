/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fixed_add_67a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67a.tmpl.c
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

typedef struct _CWE190_Integer_Overflow__char_fixed_add_67_struct_type
{
    char a;
} CWE190_Integer_Overflow__char_fixed_add_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_fixed_add_67b_bad_sink(CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct);

void CWE190_Integer_Overflow__char_fixed_add_67_bad()
{
    char data;
    CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct;
    data = ' ';
    /* FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    my_struct.a = data;
    CWE190_Integer_Overflow__char_fixed_add_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fixed_add_67b_goodG2B_sink(CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct);

static void goodG2B()
{
    char data;
    CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    my_struct.a = data;
    CWE190_Integer_Overflow__char_fixed_add_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fixed_add_67b_goodB2G_sink(CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct);

static void goodB2G()
{
    char data;
    CWE190_Integer_Overflow__char_fixed_add_67_struct_type my_struct;
    data = ' ';
    /* FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    my_struct.a = data;
    CWE190_Integer_Overflow__char_fixed_add_67b_goodB2G_sink(my_struct);
}

void CWE190_Integer_Overflow__char_fixed_add_67_good()
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
    CWE190_Integer_Overflow__char_fixed_add_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fixed_add_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
