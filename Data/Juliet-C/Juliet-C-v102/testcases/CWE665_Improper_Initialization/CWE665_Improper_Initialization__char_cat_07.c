/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_07.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-07.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE665_Improper_Initialization__char_cat_07_bad()
{
    char * data;
    char data_buf[100];
    data = data_buf;
    if(static_five==5)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, src);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_five==5 to static_five!=5 */
static void goodG2B1()
{
    char * data;
    char data_buf[100];
    data = data_buf;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, src);
        printLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char data_buf[100];
    data = data_buf;
    if(static_five==5)
    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, src);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_cat_07_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE665_Improper_Initialization__char_cat_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_cat_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif