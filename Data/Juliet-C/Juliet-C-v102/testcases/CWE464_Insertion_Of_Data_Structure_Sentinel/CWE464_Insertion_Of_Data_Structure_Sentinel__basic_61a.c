/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61a.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
char CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61b_bad_source(char data);

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61_bad()
{
    char data;
    data = ' ';
    data = CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61b_bad_source(data);
    {
        char char_array[4];
        char_array[0] = 'x';
        /* POTENTIAL FLAW: If data is null, the rest of the array will not be printed */
        char_array[1] = data;
        char_array[2] = 'z';
        char_array[3] = '\0';
        printLine(char_array);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61b_goodG2B_source(char data);

static void goodG2B()
{
    char data;
    data = ' ';
    data = CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61b_goodG2B_source(data);
    {
        char char_array[4];
        char_array[0] = 'x';
        /* POTENTIAL FLAW: If data is null, the rest of the array will not be printed */
        char_array[1] = data;
        char_array[2] = 'z';
        char_array[3] = '\0';
        printLine(char_array);
    }
}

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61_good()
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
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
