/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_34.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    wchar_t * a;
    wchar_t * b;
} CWE665_Improper_Initialization__wchar_t_cat_34_union_type;

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_cat_34_bad()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_cat_34_union_type my_union;
    wchar_t data_buf[100];
    data = data_buf;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    my_union.a = data;
    {
        wchar_t * data = my_union.b;
        {
            wchar_t src[100];
            wmemset(src, L'C', 100-1); /* fill with L'C's */
            src[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
            wcscat(data, src);
            printWLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_cat_34_union_type my_union;
    wchar_t data_buf[100];
    data = data_buf;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    my_union.a = data;
    {
        wchar_t * data = my_union.b;
        {
            wchar_t src[100];
            wmemset(src, L'C', 100-1); /* fill with L'C's */
            src[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
            wcscat(data, src);
            printWLine(data);
        }
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_34_good()
{
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
    CWE665_Improper_Initialization__wchar_t_cat_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
