/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__large_int_68a.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE129_Improper_Validation_Of_Array_Index__large_int_68_bad_data;
int CWE129_Improper_Validation_Of_Array_Index__large_int_68_goodG2B_data;
int CWE129_Improper_Validation_Of_Array_Index__large_int_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__large_int_68b_bad_sink();

void CWE129_Improper_Validation_Of_Array_Index__large_int_68_bad()
{
    int data;
    data = -1; /* Initialize data */
    /* FLAW: Use an invalid index */
    data = 10;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68_bad_data = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE129_Improper_Validation_Of_Array_Index__large_int_68b_goodG2B_sink();
void CWE129_Improper_Validation_Of_Array_Index__large_int_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68_goodG2B_data = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    /* FLAW: Use an invalid index */
    data = 10;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68_goodB2G_data = data;
    CWE129_Improper_Validation_Of_Array_Index__large_int_68b_goodB2G_sink();
}

void CWE129_Improper_Validation_Of_Array_Index__large_int_68_good()
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
    CWE129_Improper_Validation_Of_Array_Index__large_int_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__large_int_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
