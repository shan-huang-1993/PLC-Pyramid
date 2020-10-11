/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fixed_square_45.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the square root
 *    BadSink : Square data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <math.h>

static int CWE190_Integer_Overflow__int_fixed_square_45_bad_data;
static int CWE190_Integer_Overflow__int_fixed_square_45_goodG2B_data;
static int CWE190_Integer_Overflow__int_fixed_square_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_square_45_bad_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__int_fixed_square_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    CWE190_Integer_Overflow__int_fixed_square_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_square_45_goodG2B_data;
    {
        /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
        int result = data * data;
        printIntLine(result);
    }
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 5;
    CWE190_Integer_Overflow__int_fixed_square_45_goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    int data = CWE190_Integer_Overflow__int_fixed_square_45_goodB2G_data;
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

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use the maximum size of the data type */
    data = INT_MAX;
    CWE190_Integer_Overflow__int_fixed_square_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE190_Integer_Overflow__int_fixed_square_45_good()
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
    CWE190_Integer_Overflow__int_fixed_square_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fixed_square_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
