/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int_44.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_int_44
{

#ifndef OMITBAD

static void bad_sink(int * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    int * data;
    /* define a function pointer */
    void (*func_ptr) (int *) = bad_sink;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(int * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

static void goodG2B()
{
    int * data;
    void (*func_ptr) (int *) = goodG2B_sink;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    int data_good;
    data = &data_good;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    func_ptr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(int * data)
{
    /* FIX: Deallocate memory */
    delete data;
}

static void goodB2G()
{
    int * data;
    void (*func_ptr) (int *) = goodB2G_sink;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    func_ptr(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_int_44; // so that we can use good and bad easily

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