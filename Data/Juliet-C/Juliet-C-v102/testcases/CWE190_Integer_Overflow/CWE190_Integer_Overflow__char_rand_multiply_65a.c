/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_65a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_rand_multiply_65b_bad_sink(char data);

void CWE190_Integer_Overflow__char_rand_multiply_65_bad()
{
    char data;
    /* define a function pointer */
    void (*func_ptr) (char) = CWE190_Integer_Overflow__char_rand_multiply_65b_bad_sink;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_multiply_65b_goodG2B_sink(char data);

static void goodG2B()
{
    char data;
    void (*func_ptr) (char) = CWE190_Integer_Overflow__char_rand_multiply_65b_goodG2B_sink;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    func_ptr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_multiply_65b_goodB2G_sink(char data);

static void goodB2G()
{
    char data;
    void (*func_ptr) (char) = CWE190_Integer_Overflow__char_rand_multiply_65b_goodB2G_sink;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    func_ptr(data);
}

void CWE190_Integer_Overflow__char_rand_multiply_65_good()
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
    CWE190_Integer_Overflow__char_rand_multiply_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_multiply_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
