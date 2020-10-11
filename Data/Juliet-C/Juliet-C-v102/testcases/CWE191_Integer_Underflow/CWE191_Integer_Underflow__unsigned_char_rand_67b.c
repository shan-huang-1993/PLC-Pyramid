/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_rand_67b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE191_Integer_Underflow__unsigned_char_rand_67_struct_type
{
    unsigned char a;
} CWE191_Integer_Underflow__unsigned_char_rand_67_struct_type;

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_char_rand_67b_bad_sink(CWE191_Integer_Underflow__unsigned_char_rand_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned char result = data - 1;
        printHexUnsignedCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_char_rand_67b_goodG2B_sink(CWE191_Integer_Underflow__unsigned_char_rand_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned char result = data - 1;
        printHexUnsignedCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_char_rand_67b_goodB2G_sink(CWE191_Integer_Underflow__unsigned_char_rand_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
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

#endif /* OMITGOOD */
