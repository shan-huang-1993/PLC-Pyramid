/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_calloc_44.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static void bad_sink(char * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__char_calloc_44_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = bad_sink;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (char *)calloc(100, sizeof(char));
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(char * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = goodG2B_sink;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
    }
    func_ptr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(char * data)
{
    /* FIX: Deallocate memory */
    free(data);
}

static void goodB2G()
{
    char * data;
    void (*func_ptr) (char *) = goodB2G_sink;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (char *)calloc(100, sizeof(char));
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    func_ptr(data);
}

void CWE401_Memory_Leak__char_calloc_44_good()
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
    CWE401_Memory_Leak__char_calloc_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__char_calloc_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif