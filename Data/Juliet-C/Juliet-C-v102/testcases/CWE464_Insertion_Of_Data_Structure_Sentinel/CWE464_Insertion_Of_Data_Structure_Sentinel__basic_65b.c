/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_65b.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_65b_bad_sink(char data)
{
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
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_65b_goodG2B_sink(char data)
{
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
