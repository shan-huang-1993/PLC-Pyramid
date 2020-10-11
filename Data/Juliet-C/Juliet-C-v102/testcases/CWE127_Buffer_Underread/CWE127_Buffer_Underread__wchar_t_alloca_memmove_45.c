/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_memmove_45.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_bad_data;
static wchar_t * CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_bad_data;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memmove(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

void CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_bad()
{
    wchar_t * data;
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = data_buf - 8;
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_goodG2B_data;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memmove(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

static void goodG2B()
{
    wchar_t * data;
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = data_buf;
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_good()
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
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
