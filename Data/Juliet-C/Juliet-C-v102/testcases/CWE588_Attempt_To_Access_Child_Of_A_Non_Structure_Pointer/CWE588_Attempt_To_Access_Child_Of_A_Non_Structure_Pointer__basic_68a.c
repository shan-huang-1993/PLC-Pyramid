/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68a.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

void * CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_bad_data;
void * CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68b_bad_sink();

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_bad()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    /* FLAW: Set data to point to an int */
    data = &data_badbuf;
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_bad_data = data;
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    /* FIX: Set data to point to a twoints struct */
    data = &data_goodbuf;
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_goodG2B_data = data;
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68b_goodG2B_sink();
}

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_good()
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
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
