/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fgets_malloc_16.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

#ifndef OMITBAD

void CWE194_Unexpected_Sign_Extension__fgets_malloc_16_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        break;
    }
    while(1)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
        break;
    }
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    short data;
    /* Initialize data */
    data = 0;
    while(1)
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
        break;
    }
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

void CWE194_Unexpected_Sign_Extension__fgets_malloc_16_good()
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
    CWE194_Unexpected_Sign_Extension__fgets_malloc_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__fgets_malloc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif