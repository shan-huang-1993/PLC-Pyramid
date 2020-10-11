/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fscanf_12.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_fscanf_12_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        fscanf (stdin, "%d", &data);
    }
    if(global_returns_t_or_f())
    {
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
    else
    {
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

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__int_fscanf_12_good()
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
    CWE191_Integer_Underflow__int_fscanf_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_fscanf_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
