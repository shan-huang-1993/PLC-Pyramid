/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_34.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sink-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_34
{

typedef union
{
    twointsclass * a;
    twointsclass * b;
} union_type;

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    my_union.a = data;
    {
        twointsclass * data = my_union.b;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data[0].a);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twointsclass * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    {
        twointsclass * tmp = new twointsclass;
        tmp->a = 0;
        tmp->b = 0;
        /* FIX: Initialize data - it will be used in the sink */
        data = tmp;
    }
    my_union.a = data;
    {
        twointsclass * data = my_union.b;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data[0].a);
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE476_NULL_Pointer_Dereference__class_34; // so that we can use good and bad easily

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
