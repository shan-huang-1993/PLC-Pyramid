/*
 * @description Memory Leak
 * 
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__virtual_destructor_01
{

#ifndef OMITBAD

class BadBaseClass
{
	public:
		BadBaseClass(){ printLine("Constructor: BadBaseClass");}
		/* FLAW: Non-virtual destructor - the destructor of the 
		 * derived class will not be called */
		~BadBaseClass(){ printLine("Destructor : BadBaseClass");}

};
class BadDerivedClass: public BadBaseClass
{
	public:
		BadDerivedClass(){}
		BadDerivedClass(char * badName)
		{ 
			printLine("Constructor: BadDerivedClass");
			name = new char[strlen(badName) + 1];
			strcpy(name, badName);
			printLine(name);
		}
        ~BadDerivedClass(){
			/* This should never be executed */
			printLine("Destructor : BadDerivedClass");
			delete [] name;
		}

	private:
		char * name;
};

void bad()
{
    BadBaseClass * a = new BadDerivedClass("BadClass");

	delete a;
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__virtual_destructor_01; // so that we can use good and bad easily

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
