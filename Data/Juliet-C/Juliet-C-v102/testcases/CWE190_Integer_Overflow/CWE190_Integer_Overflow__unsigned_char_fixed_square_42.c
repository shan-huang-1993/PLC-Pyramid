/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fixed_square_42.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

static unsigned char bad_source(unsigned char data)
{
    /* FLAW: Use the maximum size of the data type */
    data = UCHAR_MAX;
    return data;
}

void CWE190_Integer_Overflow__unsigned_char_fixed_square_42_bad()
{
    unsigned char data;
    data = ' ';
    data = bad_source(data);
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned char result = data * data;
        printHexUnsignedCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static unsigned char goodG2B_source(unsigned char data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    return data;
}

static void goodG2B()
{
    unsigned char data;
    data = ' ';
    data = goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned char result = data * data;
        printHexUnsignedCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static unsigned char goodB2G_source(unsigned char data)
{
    /* FLAW: Use the maximum size of the data type */
    data = UCHAR_MAX;
    return data;
}

static void goodB2G()
{
    unsigned char data;
    data = ' ';
    data = goodB2G_source(data);
    {
        unsigned char result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
        {
            result = data * data;
            printHexUnsignedCharLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__unsigned_char_fixed_square_42_good()
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
    CWE190_Integer_Overflow__unsigned_char_fixed_square_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_char_fixed_square_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
