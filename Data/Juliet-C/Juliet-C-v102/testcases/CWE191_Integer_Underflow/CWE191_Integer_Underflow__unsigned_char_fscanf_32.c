/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fscanf_32.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_char_fscanf_32_bad()
{
    unsigned char data;
    unsigned char *data_ptr1 = &data;
    unsigned char *data_ptr2 = &data;
    data = ' ';
    {
        unsigned char data = *data_ptr1;
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
        *data_ptr1 = data;
    }
    {
        unsigned char data = *data_ptr2;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    unsigned char data;
    unsigned char *data_ptr1 = &data;
    unsigned char *data_ptr2 = &data;
    data = ' ';
    {
        unsigned char data = *data_ptr1;
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        *data_ptr1 = data;
    }
    {
        unsigned char data = *data_ptr2;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    unsigned char data;
    unsigned char *data_ptr1 = &data;
    unsigned char *data_ptr2 = &data;
    data = ' ';
    {
        unsigned char data = *data_ptr1;
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
        *data_ptr1 = data;
    }
    {
        unsigned char data = *data_ptr2;
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

void CWE191_Integer_Underflow__unsigned_char_fscanf_32_good()
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
    CWE191_Integer_Underflow__unsigned_char_fscanf_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fscanf_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
