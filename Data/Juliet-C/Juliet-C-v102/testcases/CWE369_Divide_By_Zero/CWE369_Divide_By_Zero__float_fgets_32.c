/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_fgets_32.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE369_Divide_By_Zero__float_fgets_32_bad()
{
    float data;
    float *data_ptr1 = &data;
    float *data_ptr2 = &data;
    /* Initialize data */
    data = 0.0F;
    {
        float data = *data_ptr1;
        {
            char input_buf[CHAR_ARRAY_SIZE];
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to float */
            data = (float)atof(input_buf);
        }
        *data_ptr1 = data;
    }
    {
        float data = *data_ptr2;
        /* POTENTIAL FLAW: Possibly divide by zero */
        printDoubleLine((double)(100.0 / data));
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    float data;
    float *data_ptr1 = &data;
    float *data_ptr2 = &data;
    /* Initialize data */
    data = 0.0F;
    {
        float data = *data_ptr1;
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
        *data_ptr1 = data;
    }
    {
        float data = *data_ptr2;
        /* POTENTIAL FLAW: Possibly divide by zero */
        printDoubleLine((double)(100.0 / data));
    }
}

void CWE369_Divide_By_Zero__float_fgets_32_good()
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
    CWE369_Divide_By_Zero__float_fgets_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_fgets_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
