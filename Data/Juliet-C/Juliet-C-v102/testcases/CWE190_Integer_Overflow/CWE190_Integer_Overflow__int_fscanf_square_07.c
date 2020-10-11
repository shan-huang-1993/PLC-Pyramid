/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_square_07.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-07.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the square root
 *    BadSink : Square data
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#include <math.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fscanf_square_07_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
    }
    if(static_five==5)
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
            int result = data * data;
            printIntLine(result);
        }
    }
    else
    {
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_five==5 to static_five!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
    }
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
            int result = data * data;
            printIntLine(result);
        }
    }
    else
    {
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
    }
    if(static_five==5)
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
            int result = data * data;
            printIntLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_five==5 to static_five!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
    }
    if(static_five==5)
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
            int result = data * data;
            printIntLine(result);
        }
    }
    else
    {
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
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_five==5)
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    if(static_five==5)
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an integer overflow */
            int result = data * data;
            printIntLine(result);
        }
    }
    else
    {
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
}

void CWE190_Integer_Overflow__int_fscanf_square_07_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE190_Integer_Overflow__int_fscanf_square_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fscanf_square_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
