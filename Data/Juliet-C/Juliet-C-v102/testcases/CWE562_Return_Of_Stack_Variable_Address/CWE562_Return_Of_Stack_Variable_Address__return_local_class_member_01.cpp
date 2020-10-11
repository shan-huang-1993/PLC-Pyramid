/*
 * @description Return of local buffer address via stack-allocated object
 * 
 * */

#include "std_testcase.h"

/* this REQUIRES secondary functions */

namespace CWE562_Return_Of_Stack_Variable_Address__return_local_class_member_01
{
    class Foo {
    private:
        int x[2];
    public:
        Foo() { x[0] = 0x41; x[1] = 0x42; }
        const int *get_x() { return x; }
    };

#ifndef OMITBAD

static const int *helper_bad()
{
    Foo foo;

    /* FLAW: returning stack-allocated buffer */
    return foo.get_x(); /* this may generate a warning -- it's on purpose */
}

void bad()
{
    printIntLine(*helper_bad());
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static const int *helper_good()
{
    static Foo foo;

    /* FIX: don't return a stack-allocated buffer
     * you can use static (i.e., global) variables but this renders your
     * code, and all code that uses it, non-re-entrant and non-threadsafe,
     * and hence is not a complete solution.  We do it anyway
     */
    return foo.get_x();
}

static void good1()
{
    printIntLine(*helper_good());
}

void good()
{
    good1();
}

#endif /* OMITGOOD */

};

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) {

    /* seed randomness */
    srand( (unsigned)time(NULL) );

#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE562_Return_Of_Stack_Variable_Address__return_local_class_member_01::good();
    printLine("Finished good()");
#endif /* OMITGOOD */

#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE562_Return_Of_Stack_Variable_Address__return_local_class_member_01::bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;

} 

#endif
