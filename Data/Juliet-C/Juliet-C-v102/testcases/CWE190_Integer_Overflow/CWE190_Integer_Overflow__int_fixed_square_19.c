/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fixed_square_19.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-19.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the square root
 *    BadSink : Square data
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fixed_square_19_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (int)sqrt((int)INT_MAX))
        {
            result = data * data;
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
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    {
        int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (int)sqrt((int)INT_MAX))
        {
            result = data * data;
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
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
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
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_fixed_square_19_good()
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
    CWE190_Integer_Overflow__int_fixed_square_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fixed_square_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
