/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_multiply_19.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-19.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_rand_multiply_19_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (INT_MAX/2))
        {
            result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by switching statements around return */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (INT_MAX/2))
        {
            result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

/* goodG2B() - use goodsource and badsink by moving BadSource and BadSink to after return */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 5;
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    data = RAND32();
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_rand_multiply_19_good()
{
    goodB2G();
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
    CWE190_Integer_Overflow__int_rand_multiply_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_rand_multiply_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
