/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_41.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static void bad_sink(wchar_t * data)
{
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__strdup_wchar_t_41_bad()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t mystring[] = L"mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(mystring);
        /* Use data */
        printWLine(data);
    }
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_sink(wchar_t * data)
{
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    {
        /* FIX: Allocate memory from the stack */
        wchar_t data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        wcscpy(data, L"a string");
        printWLine(data);
    }
    goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_sink(wchar_t * data)
{
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t mystring[] = L"mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(mystring);
        /* Use data */
        printWLine(data);
    }
    goodB2G_sink(data);
}

void CWE401_Memory_Leak__strdup_wchar_t_41_good()
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
    CWE401_Memory_Leak__strdup_wchar_t_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_wchar_t_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
