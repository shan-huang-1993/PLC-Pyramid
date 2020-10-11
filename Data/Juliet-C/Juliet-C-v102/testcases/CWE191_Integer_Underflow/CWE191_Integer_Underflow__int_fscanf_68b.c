/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fscanf_68b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE191_Integer_Underflow__int_fscanf_68_bad_data;
extern int CWE191_Integer_Underflow__int_fscanf_68_goodG2B_data;
extern int CWE191_Integer_Underflow__int_fscanf_68_goodB2G_data;

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_fscanf_68b_bad_sink()
{
    int data = CWE191_Integer_Underflow__int_fscanf_68_bad_data;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_fscanf_68b_goodG2B_sink()
{
    int data = CWE191_Integer_Underflow__int_fscanf_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_fscanf_68b_goodB2G_sink()
{
    int data = CWE191_Integer_Underflow__int_fscanf_68_goodB2G_data;
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

#endif /* OMITGOOD */
