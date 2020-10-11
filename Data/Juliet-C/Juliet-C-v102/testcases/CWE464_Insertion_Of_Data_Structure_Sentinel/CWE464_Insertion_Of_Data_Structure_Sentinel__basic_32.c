/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_32.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_32_bad()
{
    char data;
    char *data_ptr1 = &data;
    char *data_ptr2 = &data;
    data = ' ';
    {
        char data = *data_ptr1;
        {
            char ch;
            ch = (char)getc(stdin);
            /* FLAW: If the character entered on the command line is not an int,
             * a null value will be returned */
            data = (char)atoi(&ch);
        }
        *data_ptr1 = data;
    }
    {
        char data = *data_ptr2;
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    char *data_ptr1 = &data;
    char *data_ptr2 = &data;
    data = ' ';
    {
        char data = *data_ptr1;
        /* FIX: Set data to be a char */
        data = 'a';
        *data_ptr1 = data;
    }
    {
        char data = *data_ptr2;
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
}

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_32_good()
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
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
