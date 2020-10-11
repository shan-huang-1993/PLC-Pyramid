/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_realloc_68a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE401_Memory_Leak__wchar_t_realloc_68_bad_data;
wchar_t * CWE401_Memory_Leak__wchar_t_realloc_68_goodG2B_data;
wchar_t * CWE401_Memory_Leak__wchar_t_realloc_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__wchar_t_realloc_68b_bad_sink();

void CWE401_Memory_Leak__wchar_t_realloc_68_bad()
{
    wchar_t * data;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)realloc(data, 100*sizeof(wchar_t));
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_realloc_68_bad_data = data;
    CWE401_Memory_Leak__wchar_t_realloc_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE401_Memory_Leak__wchar_t_realloc_68b_goodG2B_sink();
void CWE401_Memory_Leak__wchar_t_realloc_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        wchar_t data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    CWE401_Memory_Leak__wchar_t_realloc_68_goodG2B_data = data;
    CWE401_Memory_Leak__wchar_t_realloc_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)realloc(data, 100*sizeof(wchar_t));
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_realloc_68_goodB2G_data = data;
    CWE401_Memory_Leak__wchar_t_realloc_68b_goodB2G_sink();
}

void CWE401_Memory_Leak__wchar_t_realloc_68_good()
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
    CWE401_Memory_Leak__wchar_t_realloc_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__wchar_t_realloc_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
