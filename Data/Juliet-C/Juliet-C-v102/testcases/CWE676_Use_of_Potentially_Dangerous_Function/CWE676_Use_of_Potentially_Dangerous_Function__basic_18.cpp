/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE676_Use_of_Potentially_Dangerous_Function__basic_18.cpp
Label Definition File: CWE676_Use_of_Potentially_Dangerous_Function__basic.label.xml
Template File: point-flaw-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 676 Use of Potentially Dangerous Function
 * Sinks:
 *    GoodSink: Use cin after specifying the length of the input
 *    BadSink : Use cin without specifying the length of the input
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <iostream>

using namespace std;

#define DST_SZ 10

namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_18
{

#ifndef OMITBAD

void bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char s[DST_SZ];
        /* FIX: Use cin after specifying the length of the input */
        cin.width(DST_SZ);
        cin >> s;
        s[DST_SZ-1] = '\0';
        printLine(s);
    }
sink:
    {
        char s[DST_SZ];
        /* FLAW: using cin in an inherently dangerous fashion */
        /* INCIDENTAL CWE120 Buffer Overflow since cin extraction is unbounded. */
        cin >> s;
        s[DST_SZ-1] = '\0';
        printLine(s);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char s[DST_SZ];
        /* FLAW: using cin in an inherently dangerous fashion */
        /* INCIDENTAL CWE120 Buffer Overflow since cin extraction is unbounded. */
        cin >> s;
        s[DST_SZ-1] = '\0';
        printLine(s);
    }
sink:
    {
        char s[DST_SZ];
        /* FIX: Use cin after specifying the length of the input */
        cin.width(DST_SZ);
        cin >> s;
        s[DST_SZ-1] = '\0';
        printLine(s);
    }
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

using namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_18; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
