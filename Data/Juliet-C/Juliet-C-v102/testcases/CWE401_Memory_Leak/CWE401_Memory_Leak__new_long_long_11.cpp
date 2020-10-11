/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_long_long_11.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-11.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_long_long_11
{

#ifndef OMITBAD

void bad()
{
    long long * data;
    data = NULL;
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new long long;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use memory allocated on the stack */
        long long data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_returns_t() to global_returns_f() */
static void goodB2G1()
{
    long long * data;
    data = NULL;
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new long long;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use memory allocated on the stack */
        long long data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    long long * data;
    data = NULL;
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new long long;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use memory allocated on the stack */
        long long data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    if(global_returns_t())
    {
        /* FIX: Deallocate memory */
        delete data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    long long * data;
    data = NULL;
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new long long;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        long long data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    long long * data;
    data = NULL;
    if(global_returns_t())
    {
        /* FIX: Use memory allocated on the stack */
        long long data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new long long;
        /* Initialize and make use of data */
        *data = 5L;
        printLongLongLine(*data);
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete data;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_long_long_11; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
