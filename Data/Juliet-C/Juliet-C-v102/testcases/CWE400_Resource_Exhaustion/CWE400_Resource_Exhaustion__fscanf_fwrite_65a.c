/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_65a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fscanf_fwrite_65b_bad_sink(int count);

void CWE400_Resource_Exhaustion__fscanf_fwrite_65_bad()
{
    int count;
    /* define a function pointer */
    void (*func_ptr) (int) = CWE400_Resource_Exhaustion__fscanf_fwrite_65b_bad_sink;
    /* Initialize count */
    count = -1;
    fscanf (stdin, "%d", &count);
    /* use the function pointer */
    func_ptr(count);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_65b_goodG2B_sink(int count);

static void goodG2B()
{
    int count;
    void (*func_ptr) (int) = CWE400_Resource_Exhaustion__fscanf_fwrite_65b_goodG2B_sink;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    func_ptr(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_65b_goodB2G_sink(int count);

static void goodB2G()
{
    int count;
    void (*func_ptr) (int) = CWE400_Resource_Exhaustion__fscanf_fwrite_65b_goodB2G_sink;
    /* Initialize count */
    count = -1;
    fscanf (stdin, "%d", &count);
    func_ptr(count);
}

void CWE400_Resource_Exhaustion__fscanf_fwrite_65_good()
{
    goodG2B();
    goodB2G();
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
    CWE400_Resource_Exhaustion__fscanf_fwrite_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fscanf_fwrite_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
