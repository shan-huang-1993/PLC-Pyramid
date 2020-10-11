/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_long_long_06.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-06.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

namespace CWE401_Memory_Leak__new_long_long_06
{

#ifndef OMITBAD

void bad()
{
    long long * data;
    data = NULL;
    if(static_const_five==5)
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
    if(static_const_five==5)
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

/* goodB2G1() - use badsource and goodsink by changing the second static_const_five==5 to static_const_five!=5 */
static void goodB2G1()
{
    long long * data;
    data = NULL;
    if(static_const_five==5)
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
    if(static_const_five!=5)
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
    if(static_const_five==5)
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
    if(static_const_five==5)
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

/* goodG2B1() - use goodsource and badsink by changing the first static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    long long * data;
    data = NULL;
    if(static_const_five!=5)
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
    if(static_const_five==5)
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
    if(static_const_five==5)
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
    if(static_const_five==5)
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

using namespace CWE401_Memory_Leak__new_long_long_06; // so that we can use good and bad easily

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
