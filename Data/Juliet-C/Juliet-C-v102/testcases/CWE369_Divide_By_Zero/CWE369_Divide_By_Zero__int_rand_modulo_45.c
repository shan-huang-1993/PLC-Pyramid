/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_rand_modulo_45.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int CWE369_Divide_By_Zero__int_rand_modulo_45_bad_data;
static int CWE369_Divide_By_Zero__int_rand_modulo_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    int data = CWE369_Divide_By_Zero__int_rand_modulo_45_bad_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

void CWE369_Divide_By_Zero__int_rand_modulo_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    CWE369_Divide_By_Zero__int_rand_modulo_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    int data = CWE369_Divide_By_Zero__int_rand_modulo_45_goodG2B_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    CWE369_Divide_By_Zero__int_rand_modulo_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE369_Divide_By_Zero__int_rand_modulo_45_good()
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
    CWE369_Divide_By_Zero__int_rand_modulo_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_rand_modulo_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
