/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fixed_34.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    unsigned char a;
    unsigned char b;
} CWE191_Integer_Underflow__unsigned_char_fixed_34_union_type;

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_char_fixed_34_bad()
{
    unsigned char data;
    CWE191_Integer_Underflow__unsigned_char_fixed_34_union_type my_union;
    data = ' ';
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    my_union.a = data;
    {
        unsigned char data = my_union.b;
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
    CWE191_Integer_Underflow__unsigned_char_fixed_34_union_type my_union;
    data = ' ';
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    my_union.a = data;
    {
        unsigned char data = my_union.b;
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
    CWE191_Integer_Underflow__unsigned_char_fixed_34_union_type my_union;
    data = ' ';
    /* FLAW: Use the minimum size of the data type */
    data = 0;
    my_union.a = data;
    {
        unsigned char data = my_union.b;
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

void CWE191_Integer_Underflow__unsigned_char_fixed_34_good()
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
    CWE191_Integer_Underflow__unsigned_char_fixed_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fixed_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
