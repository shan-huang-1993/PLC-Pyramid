/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fscanf_add_32.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_char_fscanf_add_32_bad()
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
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            unsigned char result = data + 1;
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
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        *data_ptr1 = data;
    }
    {
        unsigned char data = *data_ptr2;
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            unsigned char result = data + 1;
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
}

void CWE190_Integer_Overflow__unsigned_char_fscanf_add_32_good()
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
    CWE190_Integer_Overflow__unsigned_char_fscanf_add_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_char_fscanf_add_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
