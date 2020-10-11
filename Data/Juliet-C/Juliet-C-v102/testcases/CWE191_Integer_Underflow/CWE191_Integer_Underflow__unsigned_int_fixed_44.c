/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_fixed_44.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void bad_sink(unsigned int data)
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

void CWE191_Integer_Underflow__unsigned_int_fixed_44_bad()
{
    unsigned int data;
    /* define a function pointer */
    void (*func_ptr) (unsigned int) = bad_sink;
    data = 0;
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(unsigned int data)
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

static void goodG2B()
{
    unsigned int data;
    void (*func_ptr) (unsigned int) = goodG2B_sink;
    data = 0;
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    func_ptr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(unsigned int data)
{
    {
        unsigned int result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > 0)
        {
            result = data - 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
}

static void goodB2G()
{
    unsigned int data;
    void (*func_ptr) (unsigned int) = goodB2G_sink;
    data = 0;
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    func_ptr(data);
}

void CWE191_Integer_Underflow__unsigned_int_fixed_44_good()
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
    CWE191_Integer_Underflow__unsigned_int_fixed_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_fixed_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
