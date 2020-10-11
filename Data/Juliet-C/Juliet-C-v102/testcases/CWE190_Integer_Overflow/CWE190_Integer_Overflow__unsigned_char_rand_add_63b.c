/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_rand_add_63b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_char_rand_add_63b_bad_sink(unsigned char * data_ptr)
{
    unsigned char data = *data_ptr;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned char result = data + 1;
        printHexUnsignedCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_char_rand_add_63b_goodG2B_sink(unsigned char * data_ptr)
{
    unsigned char data = *data_ptr;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned char result = data + 1;
        printHexUnsignedCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_char_rand_add_63b_goodB2G_sink(unsigned char * data_ptr)
{
    unsigned char data = *data_ptr;
    {
        unsigned char result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UCHAR_MAX)
        {
            result = data + 1;
            printHexUnsignedCharLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
