/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_18.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_struct_18_bad()
{
    twoints data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Initialize and use data before it is overwritten */
    data.a = 0;
    data.b = 0;
    printStructLine(&data);
source:
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.a = 0;
    data.b = 0;
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use data without over-writing its value */
    printStructLine(&data);
sink:
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.a = 1;
    data.b = 1;
    printStructLine(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    twoints data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Initialize and use data before it is overwritten */
    data.a = 0;
    data.b = 0;
    printStructLine(&data);
source:
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.a = 0;
    data.b = 0;
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.a = 1;
    data.b = 1;
    printStructLine(&data);
sink:
    /* FIX: Use data without over-writing its value */
    printStructLine(&data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    twoints data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.a = 0;
    data.b = 0;
source:
    /* FIX: Initialize and use data before it is overwritten */
    data.a = 0;
    data.b = 0;
    printStructLine(&data);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use data without over-writing its value */
    printStructLine(&data);
sink:
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.a = 1;
    data.b = 1;
    printStructLine(&data);
}

void CWE563_Unused_Variable__unused_value_struct_18_good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE563_Unused_Variable__unused_value_struct_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_struct_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
