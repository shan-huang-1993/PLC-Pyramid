/*
 * @description Exceptional Conditions
 * 
 * */

#include "std_testcase.h"

namespace CWE416_Use_After_Free__operator_equals_01
{

#ifndef OMITGOOD

	class GoodClass {

	public:
		GoodClass() {
			name = NULL;
		}
		
		GoodClass(const char * _name) {
			name = new char[strlen(_name) + 1];
			strcpy(name, _name);
		}

		~GoodClass() {
			delete [] name;
		}
		
		GoodClass& operator=(const GoodClass& rhs) {
		    /* FIX - Check for self assignment and basically do nothing in that case */
			if (this != &rhs) {
				delete [] this->name;
				this->name = new char[strlen(rhs.name)+1]; 
				strcpy(this->name, rhs.name);
			}
			return *this;
		}
		
		char * name;
	};
static void good1()
{
    GoodClass a("GoodClass");
	a = a;
	printLine(a.name);
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

using namespace CWE416_Use_After_Free__operator_equals_01; // so that we can use good and bad easily

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
