/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01.c
Label Definition File: CWE468_Incorrect_Pointer_Scaling.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 468 Incorrect Pointer Scaling
 * Sinks: char_ptr_to_int
 *    GoodSink: Correctly use sizeof() for pointer scaling
 *    BadSink : Do not use sizeof() in pointer scaling
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_bad()
{
    {
        int array[5] = { 1, 2, 3, 4, 5 };
        char *pointer = (char *)array; /* get a char pointer to array - common idiom in file and network packet parsing */
        /* get array[2] */
        /* FLAW: sizeof() needed since pointer is a char*, not an int* */
        int toPrint = (int) (*(pointer+2));
        printIntLine(toPrint);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        int array[5] = { 1, 2, 3, 4, 5 };
        char *pointer = (char *)array; /* get a char pointer to array - common idiom in file and network packet parsing */
        /* get array[2] */
        /* FIX: add *sizeof(int) to account for the difference in pointer types */
        int toPrint = (int) (*(pointer+(2*sizeof(int))));
        printIntLine(toPrint);
    }
}

void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_good()
{
    good1();
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
    CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
