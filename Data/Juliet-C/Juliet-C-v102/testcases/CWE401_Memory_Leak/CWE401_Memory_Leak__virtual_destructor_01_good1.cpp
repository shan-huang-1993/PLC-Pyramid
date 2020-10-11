/*
 * @description Memory Leak
 * 
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__virtual_destructor_01
{

#ifndef OMITGOOD

class GoodBaseClass
{
	public:
		GoodBaseClass(){ printLine("Constructor: GoodBaseClass");}
		/* FIX: Use a virtual destructor in the base class */
		virtual ~GoodBaseClass(){ printLine("Destructor : GoodBaseClass");}

};
class GoodDerivedClass: public GoodBaseClass
{
	public:
		GoodDerivedClass(){}
		GoodDerivedClass(char * badName)
		{ 
			printLine("Constructor: GoodDerivedClass");
			name = new char[strlen(badName) + 1];
			strcpy(name, badName);
			printLine(name);
		}
        ~GoodDerivedClass(){ 
			printLine("Destructor : GoodDerivedClass");
			delete [] name;
		}

	private:
		char * name;
};

static void good1()
{
    GoodBaseClass * a = new GoodDerivedClass("GoodClass");

	delete a;
}

void good()
{
    good1();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
