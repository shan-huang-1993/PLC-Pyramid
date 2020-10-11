/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__twoints_pointer_alloca_use_07.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE758_Undefined_Behavior__twoints_pointer_alloca_use_07_bad()
{
    if(static_five==5)
    {
        {
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            twoints * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printIntLine(data->a);
            printIntLine(data->b);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            twoints * data;
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_five!=5) instead of if(static_five==5) */
static void good1()
{
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            twoints * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printIntLine(data->a);
            printIntLine(data->b);
        }
    }
    else
    {
        {
            twoints * data;
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_five==5)
    {
        {
            twoints * data;
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            twoints * * pointer = (twoints * *)ALLOCA(sizeof(twoints *));
            twoints * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printIntLine(data->a);
            printIntLine(data->b);
        }
    }
}

void CWE758_Undefined_Behavior__twoints_pointer_alloca_use_07_good()
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
    CWE758_Undefined_Behavior__twoints_pointer_alloca_use_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__twoints_pointer_alloca_use_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
