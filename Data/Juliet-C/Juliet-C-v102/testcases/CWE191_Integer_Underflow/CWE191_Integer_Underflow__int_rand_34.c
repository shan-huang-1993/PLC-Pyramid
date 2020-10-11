/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_rand_34.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int a;
    int b;
} CWE191_Integer_Underflow__int_rand_34_union_type;

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_rand_34_bad()
{
    int data;
    CWE191_Integer_Underflow__int_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    data = RAND32();
    my_union.a = data;
    {
        int data = my_union.b;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    CWE191_Integer_Underflow__int_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    my_union.a = data;
    {
        int data = my_union.b;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    CWE191_Integer_Underflow__int_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    data = RAND32();
    my_union.a = data;
    {
        int data = my_union.b;
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

void CWE191_Integer_Underflow__int_rand_34_good()
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
    CWE191_Integer_Underflow__int_rand_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_rand_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
