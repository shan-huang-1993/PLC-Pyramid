/*
 * @description Use of Uninitialized Variable 
 * 
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__no_constructor_01
{

#ifndef OMITBAD

	class BadClass {

	public:
		int a;
		/* FLAW: No constructor, so a is not initialized */

	};

void bad()
{
	/* use the class */
    BadClass * data = new BadClass;
	printIntLine(data->a);
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__no_constructor_01; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
