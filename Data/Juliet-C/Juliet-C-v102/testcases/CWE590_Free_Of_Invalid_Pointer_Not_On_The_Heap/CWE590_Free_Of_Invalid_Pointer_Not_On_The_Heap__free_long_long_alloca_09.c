/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_09.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_09_bad()
{
    long long * data;
    data = NULL; /* Initialize data */
    if(global_const_t)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            long long * data_buf = (long long *)ALLOCA(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            long long * data_buf = (long long *)malloc(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_const_t to global_const_f */
static void goodG2B1()
{
    long long * data;
    data = NULL; /* Initialize data */
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            long long * data_buf = (long long *)ALLOCA(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            long long * data_buf = (long long *)malloc(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    long long * data;
    data = NULL; /* Initialize data */
    if(global_const_t)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            long long * data_buf = (long long *)malloc(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            long long * data_buf = (long long *)ALLOCA(100*sizeof(long long));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5L;
                }
            }
            data = data_buf;
        }
    }
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_09_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
