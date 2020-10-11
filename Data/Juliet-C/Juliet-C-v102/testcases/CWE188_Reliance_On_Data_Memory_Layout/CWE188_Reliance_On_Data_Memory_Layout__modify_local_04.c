/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_On_Data_Memory_Layout__modify_local_04.c
Label Definition File: CWE188_Reliance_On_Data_Memory_Layout.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_04_bad()
{
    if(static_const_t)
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
    else
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

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
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
    else
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

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
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
    else
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
}

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_04_good()
{
    good1();
    good2();
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
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
