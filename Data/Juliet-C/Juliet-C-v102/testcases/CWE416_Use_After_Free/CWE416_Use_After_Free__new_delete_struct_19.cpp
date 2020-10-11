/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_struct_19.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-19.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 19 Control flow: Dead code after a return
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_struct_19
{

#ifndef OMITBAD

void bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    data->a = 1;
    data->b = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by switching statements around return */
static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    data->a = 1;
    data->b = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* goodG2B() - use goodsource and badsink by moving BadSource and BadSink to after return */
static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    data->a = 1;
    data->b = 2;
    /* FIX: Do not delete data in the source */
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    data = new twoints;
    data->a = 1;
    data->b = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
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

using namespace CWE416_Use_After_Free__new_delete_struct_19; // so that we can use good and bad easily

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
