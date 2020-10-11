/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memcpy_32.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__char_declare_memcpy_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_badbuf[50];
    char data_goodbuf[100];
    memset(data_badbuf, 'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = '\0'; /* null terminate */
    memset(data_goodbuf, 'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = '\0'; /* null terminate */
    {
        char * data = *data_ptr1;
        /* FLAW: Set data pointer to a small buffer */
        data = data_badbuf;
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char dest[100];
            memset(dest, 'C', 100-1);
            dest[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: using memcpy with the length of the dest where data
             * could be smaller than dest causing buffer overread */
            memcpy(dest, data, strlen(dest)*sizeof(char));
            dest[100-1] = '\0';
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_badbuf[50];
    char data_goodbuf[100];
    memset(data_badbuf, 'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = '\0'; /* null terminate */
    memset(data_goodbuf, 'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = '\0'; /* null terminate */
    {
        char * data = *data_ptr1;
        /* FIX: Set data pointer to a large buffer */
        data = data_goodbuf;
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char dest[100];
            memset(dest, 'C', 100-1);
            dest[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: using memcpy with the length of the dest where data
             * could be smaller than dest causing buffer overread */
            memcpy(dest, data, strlen(dest)*sizeof(char));
            dest[100-1] = '\0';
            printLine(dest);
        }
    }
}

void CWE126_Buffer_Overread__char_declare_memcpy_32_good()
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
    CWE126_Buffer_Overread__char_declare_memcpy_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__char_declare_memcpy_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
