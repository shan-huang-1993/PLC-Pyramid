/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fscanf_67a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type
{
    unsigned char a;
} CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__unsigned_char_fscanf_67b_bad_sink(CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct);

void CWE191_Integer_Underflow__unsigned_char_fscanf_67_bad()
{
    unsigned char data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hc", &data);
    my_struct.a = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_char_fscanf_67b_goodG2B_sink(CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct);

static void goodG2B()
{
    unsigned char data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct;
    data = ' ';
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    my_struct.a = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_char_fscanf_67b_goodB2G_sink(CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct);

static void goodB2G()
{
    unsigned char data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67_struct_type my_struct;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hc", &data);
    my_struct.a = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_67b_goodB2G_sink(my_struct);
}

void CWE191_Integer_Underflow__unsigned_char_fscanf_67_good()
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
    CWE191_Integer_Underflow__unsigned_char_fscanf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fscanf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
