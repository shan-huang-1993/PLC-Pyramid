/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fixed_65a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__unsigned_char_fixed_65b_bad_sink(unsigned char data);

void CWE191_Integer_Underflow__unsigned_char_fixed_65_bad()
{
    unsigned char data;
    /* define a function pointer */
    void (*func_ptr) (unsigned char) = CWE191_Integer_Underflow__unsigned_char_fixed_65b_bad_sink;
    data = ' ';
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_char_fixed_65b_goodG2B_sink(unsigned char data);

static void goodG2B()
{
    unsigned char data;
    void (*func_ptr) (unsigned char) = CWE191_Integer_Underflow__unsigned_char_fixed_65b_goodG2B_sink;
    data = ' ';
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    func_ptr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_char_fixed_65b_goodB2G_sink(unsigned char data);

static void goodB2G()
{
    unsigned char data;
    void (*func_ptr) (unsigned char) = CWE191_Integer_Underflow__unsigned_char_fixed_65b_goodB2G_sink;
    data = ' ';
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    func_ptr(data);
}

void CWE191_Integer_Underflow__unsigned_char_fixed_65_good()
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
    CWE191_Integer_Underflow__unsigned_char_fixed_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fixed_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
