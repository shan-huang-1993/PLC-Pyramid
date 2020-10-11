/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twoints_pointer_12.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_12_bad()
{
    twoints * data;
    if(global_returns_t_or_f())
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
    }
    if(global_returns_t_or_f())
    {
        printIntLine(data->a);
        printIntLine(data->b);
    }
    else
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
        printIntLine(data->a);
        printIntLine(data->b);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    twoints * data;
    if(global_returns_t_or_f())
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(global_returns_t_or_f())
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
        printIntLine(data->a);
        printIntLine(data->b);
    }
    else
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
        printIntLine(data->a);
        printIntLine(data->b);
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    twoints * data;
    if(global_returns_t_or_f())
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
    }
    else
    {
        /* initialize both the pointer and the data pointed to */
        data = (twoints *)malloc(sizeof(twoints));
        data->a = 5;
        data->b = 6;
    }
    if(global_returns_t_or_f())
    {
        printIntLine(data->a);
        printIntLine(data->b);
    }
    else
    {
        printIntLine(data->a);
        printIntLine(data->b);
    }
}

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_12_good()
{
    goodB2G();
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
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
