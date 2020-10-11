/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_add_68b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_bad_data;
extern unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_goodG2B_data;
extern unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_goodB2G_data;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fscanf_add_68b_bad_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_bad_data;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_fscanf_add_68b_goodG2B_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_fscanf_add_68b_goodB2G_sink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_fscanf_add_68_goodB2G_data;
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
