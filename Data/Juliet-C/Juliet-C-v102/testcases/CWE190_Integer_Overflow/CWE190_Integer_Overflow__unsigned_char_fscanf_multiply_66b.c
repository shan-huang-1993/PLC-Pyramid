/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fscanf_multiply_66b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_char_fscanf_multiply_66b_bad_sink(unsigned char data_array[])
{
    /* copy data out of data_array */
    unsigned char data = data_array[2];
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        unsigned char result = data * 2;
        printHexUnsignedCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_char_fscanf_multiply_66b_goodG2B_sink(unsigned char data_array[])
{
    unsigned char data = data_array[2];
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        unsigned char result = data * 2;
        printHexUnsignedCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_char_fscanf_multiply_66b_goodB2G_sink(unsigned char data_array[])
{
    unsigned char data = data_array[2];
    {
        unsigned char result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (UCHAR_MAX/2))
        {
            result = data * 2;
            printHexUnsignedCharLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
