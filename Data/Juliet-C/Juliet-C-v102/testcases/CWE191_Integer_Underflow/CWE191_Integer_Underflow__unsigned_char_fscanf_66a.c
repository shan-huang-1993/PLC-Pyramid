/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fscanf_66a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__unsigned_char_fscanf_66b_bad_sink(unsigned char data_array[]);

void CWE191_Integer_Underflow__unsigned_char_fscanf_66_bad()
{
    unsigned char data;
    unsigned char data_array[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hc", &data);
    /* put data in array */
    data_array[2] = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_char_fscanf_66b_goodG2B_sink(unsigned char data_array[]);

static void goodG2B()
{
    unsigned char data;
    unsigned char data_array[5];
    data = ' ';
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    data_array[2] = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_66b_goodG2B_sink(data_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_char_fscanf_66b_goodB2G_sink(unsigned char data_array[]);

static void goodB2G()
{
    unsigned char data;
    unsigned char data_array[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hc", &data);
    data_array[2] = data;
    CWE191_Integer_Underflow__unsigned_char_fscanf_66b_goodB2G_sink(data_array);
}

void CWE191_Integer_Underflow__unsigned_char_fscanf_66_good()
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
    CWE191_Integer_Underflow__unsigned_char_fscanf_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fscanf_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
