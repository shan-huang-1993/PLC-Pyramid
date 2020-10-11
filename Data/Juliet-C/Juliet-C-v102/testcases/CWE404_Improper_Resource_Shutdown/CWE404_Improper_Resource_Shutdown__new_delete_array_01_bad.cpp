/*
 * @description Improper Resource Shutdown or Release
 * 
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__new_delete_array_01
{

#ifndef OMITBAD

	class BadClass {

	public:
	
		BadClass(char letter){
			
			badname = new char;
			memcpy(badname, &letter, sizeof(char));
		}

		~BadClass(){
			/* FLAW: Using delete [] to deallocate memory allocated with new */
			delete [] badname;
		}

		void printLetter(){
			printf("%c\n", *badname);
		}

	private:

		char * badname;
	};

void bad()
{
    BadClass a = BadClass('B');

	a.printLetter();
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__new_delete_array_01; // so that we can use good and bad easily

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
