/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_fromConsole_67a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

typedef struct _CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type
{
    char * a;
} CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_bad_sink(CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct);

void CWE606_Unchecked_Loop_Condition__char_fromConsole_67_bad()
{
    char * data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgets(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    my_struct.a = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_goodG2B_sink(CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Set data to a number less than MAX_LOOP */
    strcpy(data, "15");
    my_struct.a = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_goodB2G_sink(CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct);

static void goodB2G()
{
    char * data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgets(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    my_struct.a = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67b_goodB2G_sink(my_struct);
}

void CWE606_Unchecked_Loop_Condition__char_fromConsole_67_good()
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
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__char_fromConsole_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
