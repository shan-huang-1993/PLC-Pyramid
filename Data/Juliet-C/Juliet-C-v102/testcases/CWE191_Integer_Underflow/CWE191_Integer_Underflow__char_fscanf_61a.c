/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fscanf_61a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
char CWE191_Integer_Underflow__char_fscanf_61b_bad_source(char data);

void CWE191_Integer_Underflow__char_fscanf_61_bad()
{
    char data;
    data = ' ';
    data = CWE191_Integer_Underflow__char_fscanf_61b_bad_source(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char CWE191_Integer_Underflow__char_fscanf_61b_goodG2B_source(char data);

static void goodG2B()
{
    char data;
    data = ' ';
    data = CWE191_Integer_Underflow__char_fscanf_61b_goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
char CWE191_Integer_Underflow__char_fscanf_61b_goodB2G_source(char data);

static void goodB2G()
{
    char data;
    data = ' ';
    data = CWE191_Integer_Underflow__char_fscanf_61b_goodB2G_source(data);
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
}

void CWE191_Integer_Underflow__char_fscanf_61_good()
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
    CWE191_Integer_Underflow__char_fscanf_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_fscanf_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
