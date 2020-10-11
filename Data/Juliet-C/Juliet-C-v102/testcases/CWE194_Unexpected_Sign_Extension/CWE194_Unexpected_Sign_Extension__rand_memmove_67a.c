/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_memmove_67a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of rand(), which could be negative
 * GoodSource: Positive integer
 * Sinks: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type
{
    short a;
} CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__rand_memmove_67b_bad_sink(CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type my_struct);

void CWE194_Unexpected_Sign_Extension__rand_memmove_67_bad()
{
    short data;
    CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type my_struct;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use a random value that could be less than 0 */
    data = (short)RAND32();
    my_struct.a = data;
    CWE194_Unexpected_Sign_Extension__rand_memmove_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__rand_memmove_67b_goodG2B_sink(CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type my_struct);

static void goodG2B()
{
    short data;
    CWE194_Unexpected_Sign_Extension__rand_memmove_67_struct_type my_struct;
    /* Initialize data */
    data = 0;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    my_struct.a = data;
    CWE194_Unexpected_Sign_Extension__rand_memmove_67b_goodG2B_sink(my_struct);
}

void CWE194_Unexpected_Sign_Extension__rand_memmove_67_good()
{
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
    CWE194_Unexpected_Sign_Extension__rand_memmove_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__rand_memmove_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
