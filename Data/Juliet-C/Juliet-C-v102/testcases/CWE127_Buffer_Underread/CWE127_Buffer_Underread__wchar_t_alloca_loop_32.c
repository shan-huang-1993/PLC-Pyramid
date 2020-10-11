/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_loop_32.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE127_Buffer_Underread__wchar_t_alloca_loop_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    {
        wchar_t * data = *data_ptr1;
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            size_t i;
            wchar_t dest[100];
            wmemset(dest, L'C', 100-1); /* fill with 'C's */
            dest[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
            for (i = 0; i < 100; i++)
            {
                dest[i] = data[i];
            }
            /* Ensure null termination */
            dest[100-1] = L'\0';
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    {
        wchar_t * data = *data_ptr1;
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            size_t i;
            wchar_t dest[100];
            wmemset(dest, L'C', 100-1); /* fill with 'C's */
            dest[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
            for (i = 0; i < 100; i++)
            {
                dest[i] = data[i];
            }
            /* Ensure null termination */
            dest[100-1] = L'\0';
            printWLine(dest);
        }
    }
}

void CWE127_Buffer_Underread__wchar_t_alloca_loop_32_good()
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
    CWE127_Buffer_Underread__wchar_t_alloca_loop_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__wchar_t_alloca_loop_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif