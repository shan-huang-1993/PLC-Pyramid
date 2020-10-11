/*
 * @description Improper Resource Shutdown or Release
 * 
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__malloc_delete_01
{

#ifndef OMITGOOD

	class GoodClass {

	public:
	
		GoodClass(char * name){
			
			goodname = (char *)malloc(strlen(name)+1);
			strcpy(goodname, name);
		}

		~GoodClass(){
			/* FIX: Use free() to deallocate memory allocated with malloc() */
			free(goodname);
		}

		void printName(){
			printLine(goodname);
		}

	private:

		char * goodname;
	};

static void good1()
{
    GoodClass a = GoodClass("GoodClass");

	a.printName();
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

using namespace CWE404_Improper_Resource_Shutdown__malloc_delete_01; // so that we can use good and bad easily

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
