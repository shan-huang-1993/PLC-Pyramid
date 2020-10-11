/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_struct_12.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_12
{

#ifndef OMITBAD

void bad()
{
    twoints * data;
    /* Initialize data*/
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new twoints;
    }
    else
    {
        /* FIX: Allocate memory from the heap using malloc() */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        free(data);
    }
    else
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
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
    /* Initialize data*/
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new twoints;
    }
    else
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new twoints;
    }
    if(global_returns_t_or_f())
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
    else
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    twoints * data;
    /* Initialize data*/
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* FIX: Allocate memory from the heap using malloc() */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    else
    {
        /* FIX: Allocate memory from the heap using malloc() */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        free(data);
    }
    else
    {
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        free(data);
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_12; // so that we can use good and bad easily

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