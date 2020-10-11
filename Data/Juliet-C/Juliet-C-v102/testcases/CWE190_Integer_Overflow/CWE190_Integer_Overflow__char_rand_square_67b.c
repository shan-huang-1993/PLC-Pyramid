/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_square_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE190_Integer_Overflow__char_rand_square_67_struct_type
{
    char a;
} CWE190_Integer_Overflow__char_rand_square_67_struct_type;

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_rand_square_67b_bad_sink(CWE190_Integer_Overflow__char_rand_square_67_struct_type my_struct)
{
    char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        char result = data * data;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_square_67b_goodG2B_sink(CWE190_Integer_Overflow__char_rand_square_67_struct_type my_struct)
{
    char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        char result = data * data;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_square_67b_goodB2G_sink(CWE190_Integer_Overflow__char_rand_square_67_struct_type my_struct)
{
    char data = my_struct.a;
    {
        char result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (char)sqrt((char)CHAR_MAX))
        {
            result = data * data;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
