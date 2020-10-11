/*
 * @description Memory Leak
 * 
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__destructor_01
{

#ifndef OMITBAD

	class BadClass {

	public:
		BadClass(const char * name){
			badname = new char[strlen(name) + 1];
			strcpy(badname, name);
		}

		~BadClass(){
			/* FLAW: Don't deallocate memory in the destructor that was allocated in the constructor */
		}

		void printName(){
			printLine(badname);
		}

	private:
		char * badname;
	};

void bad()
{
    BadClass a = BadClass("BadClass");

	a.printName();
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__destructor_01; // so that we can use good and bad easily

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