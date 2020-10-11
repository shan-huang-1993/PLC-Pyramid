/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-41.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_bad_sink(void * data)
{
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_bad()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    /* FLAW: Set data to point to an int */
    data = &data_badbuf;
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_goodG2B_sink(void * data)
{
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

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
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_goodG2B_sink(data);
}

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_good()
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
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
