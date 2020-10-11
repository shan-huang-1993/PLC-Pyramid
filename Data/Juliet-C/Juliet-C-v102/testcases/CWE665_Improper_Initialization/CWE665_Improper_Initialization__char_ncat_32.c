/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_32.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE665_Improper_Initialization__char_ncat_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_buf[100];
    data = data_buf;
    {
        char * data = *data_ptr1;
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            size_t src_len;
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            src_len = strlen(src);
            /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
            strncat(data, src, src_len);
            printLine(data);
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
    char data_buf[100];
    data = data_buf;
    {
        char * data = *data_ptr1;
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            size_t src_len;
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            src_len = strlen(src);
            /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
            strncat(data, src, src_len);
            printLine(data);
        }
    }
}

void CWE665_Improper_Initialization__char_ncat_32_good()
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
    CWE665_Improper_Initialization__char_ncat_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
