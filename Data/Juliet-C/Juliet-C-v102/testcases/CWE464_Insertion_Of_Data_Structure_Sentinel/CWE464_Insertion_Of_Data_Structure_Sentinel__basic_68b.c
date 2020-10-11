/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68b.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern char CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68_bad_data;
extern char CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68b_bad_sink()
{
    char data = CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68_bad_data;
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
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68b_goodG2B_sink()
{
    char data = CWE464_Insertion_Of_Data_Structure_Sentinel__basic_68_goodG2B_data;
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

#endif /* OMITGOOD */
