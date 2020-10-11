/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_malloc_use_17.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_long_malloc_use_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            long long * pointer = (long long *)malloc(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printLongLongLine(data);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long data;
            long long * pointer = (long long *)malloc(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
            free(pointer);
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
            long long * pointer = (long long *)malloc(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printLongLongLine(data);
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            long long data;
            long long * pointer = (long long *)malloc(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
            free(pointer);
        }
    }
}

void CWE758_Undefined_Behavior__long_long_malloc_use_17_good()
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
    CWE758_Undefined_Behavior__long_long_malloc_use_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__long_long_malloc_use_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif