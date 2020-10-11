/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67a.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type
{
    char a;
} CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67b_bad_sink(CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type my_struct);

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_bad()
{
    char data;
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type my_struct;
    data = ' ';
    {
        char ch;
        ch = (char)getc(stdin);
        /* FLAW: If the character entered on the command line is not an int,
         * a null value will be returned */
        data = (char)atoi(&ch);
    }
    my_struct.a = data;
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67b_goodG2B_sink(CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type my_struct);

static void goodG2B()
{
    char data;
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_struct_type my_struct;
    data = ' ';
    /* FIX: Set data to be a char */
    data = 'a';
    my_struct.a = data;
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67b_goodG2B_sink(my_struct);
}

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_good()
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
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
