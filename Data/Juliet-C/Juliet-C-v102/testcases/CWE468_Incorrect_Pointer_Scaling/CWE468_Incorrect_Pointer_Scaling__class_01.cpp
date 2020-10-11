/*
* @description incorrect pointer scaling
* 
* */

#include "std_testcase.h"

namespace CWE468_Incorrect_Pointer_Scaling__class_01 {

class Foo {
public:
    Foo() : x(0) { }
    ~Foo() { }
    int x;
};

#ifndef OMITBAD

void bad() {
    Foo array[5];
    Foo *p = array;

    /* FLAW: sizeof was used to get the 3rd element
	*        but it is unnecessary because pointer scaling is done automatically 
	*/
    printIntLine((p + 3 * sizeof(Foo))->x);
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static void good1() {
    Foo array[5];
    Foo *p = array;

    /* FIX: No sizeof necessary because pointer scaling is done automatically */
    printIntLine((p + 3)->x);
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
    CWE468_Incorrect_Pointer_Scaling__class_01::good();
    printLine("Finished good()");
#endif /* OMITGOOD */

#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE468_Incorrect_Pointer_Scaling__class_01::bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
