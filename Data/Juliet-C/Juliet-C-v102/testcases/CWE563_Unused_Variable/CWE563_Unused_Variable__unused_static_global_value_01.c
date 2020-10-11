/*
 * @description Unused static global value
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static int static_global_bad = 0;

void CWE563_Unused_Variable__unused_static_global_value_01_bad() {
	/* FLAW: Overwrite the initial value of the static global variable before use */
	static_global_bad = 10;
	printIntLine(static_global_bad);
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static int static_global_good1 = 5;

static void good1() 
{
	/* FIX: Do not overwrite the value of the static global variable before use */
	printIntLine(static_global_good1);
}

void CWE563_Unused_Variable__unused_static_global_value_01_good() 
{
    good1();
}

#endif /* OMITGOOD */

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
    CWE563_Unused_Variable__unused_static_global_value_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */

#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_static_global_value_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;

} 

#endif