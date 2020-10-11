/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_66b.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_66
{

#ifndef OMITBAD

void bad_sink(int data_array[])
{
    /* copy data out of data_array */
    int data = data_array[2];
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(int data_array[])
{
    int data = data_array[2];
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

#endif /* OMITGOOD */

} // close namespace
