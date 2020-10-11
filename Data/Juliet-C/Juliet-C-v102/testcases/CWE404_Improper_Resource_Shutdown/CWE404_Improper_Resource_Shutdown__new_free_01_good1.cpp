/*
 * @description Improper Resource Shutdown or Release
 * 
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__new_free_01
{

#ifndef OMITGOOD

	class GoodClass {

	public:
	
		GoodClass(char letter){
			
			goodname = new char;
			memcpy(goodname, &letter, sizeof(char));
		}

		~GoodClass(){
			/* FIX: Use delete to deallocate memory allocated with malloc() */
			delete goodname;
		}

		void printLetter(){
			printf("%c\n", *goodname);
		}

	private:

		char * goodname;
	};

static void good1()
{
    GoodClass a = GoodClass('G');

	a.printLetter();
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

using namespace CWE404_Improper_Resource_Shutdown__new_free_01; // so that we can use good and bad easily

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
