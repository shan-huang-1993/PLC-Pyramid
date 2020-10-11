/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_multiply_61a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int CWE190_Integer_Overflow__int_rand_multiply_61b_bad_source(int data);

void CWE190_Integer_Overflow__int_rand_multiply_61_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE190_Integer_Overflow__int_rand_multiply_61b_bad_source(data);
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int CWE190_Integer_Overflow__int_rand_multiply_61b_goodG2B_source(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE190_Integer_Overflow__int_rand_multiply_61b_goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
        int result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
int CWE190_Integer_Overflow__int_rand_multiply_61b_goodB2G_source(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE190_Integer_Overflow__int_rand_multiply_61b_goodB2G_source(data);
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

void CWE190_Integer_Overflow__int_rand_multiply_61_good()
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
    CWE190_Integer_Overflow__int_rand_multiply_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_rand_multiply_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
