/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_On_Data_Memory_Layout__modify_local_17.c
Label Definition File: CWE188_Reliance_On_Data_Memory_Layout.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            struct
            {
                char first;
                int second;
            } s;
            char *c;
            s.first = 1;
            c = &s.first;
            /* FLAW: Attempt to modify 'second' assuming second comes after first and
             * is aligned on an int-boundary after first
             */
            *(int*)(c + sizeof(int)) = 5;
            printIntLine(s.first);
            printIntLine(s.second);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            struct
            {
                char first;
                int second;
            } s;
            s.first = 1;
            /* FIX: Do not make unwarranted assumptions about underlying data model
             * Modify and access data appropriately */
            s.second = 5;
            printIntLine(s.first);
            printIntLine(s.second);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            struct
            {
                char first;
                int second;
            } s;
            char *c;
            s.first = 1;
            c = &s.first;
            /* FLAW: Attempt to modify 'second' assuming second comes after first and
             * is aligned on an int-boundary after first
             */
            *(int*)(c + sizeof(int)) = 5;
            printIntLine(s.first);
            printIntLine(s.second);
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            struct
            {
                char first;
                int second;
            } s;
            s.first = 1;
            /* FIX: Do not make unwarranted assumptions about underlying data model
             * Modify and access data appropriately */
            s.second = 5;
            printIntLine(s.first);
            printIntLine(s.second);
        }
    }
}

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_17_good()
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
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
