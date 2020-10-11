/*
 * @description Exceptional Conditions
 * 
 * */

#include "std_testcase.h"

namespace CWE416_Use_After_Free__operator_equals_01
{

#ifndef OMITBAD

	class BadClass {

	public:
		BadClass() {
			name = NULL;
		}
	
		BadClass(const char * _name){
			name = new char[strlen(_name) + 1];
			strcpy(name, _name);
		}

		~BadClass(){
			delete [] name;
		}
		
		BadClass& operator=(const BadClass& rhs) {
		    /* No check for self-assignment */
			delete [] this->name;
			this->name = new char[strlen(rhs.name)+1]; 
			strcpy(this->name, rhs.name); /* FLAW - if this is a self-assignment, rhs.name has 
				already been delete'd, so this is a use after free (CWE-416). */
			return *this;
		}
		
		char * name;
	};

void bad()
{
    BadClass a("BadClass");
	a = a;
	printLine(a.name);
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE416_Use_After_Free__operator_equals_01; // so that we can use good and bad easily

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
