/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_long_long_static_12.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_long_long_static_12
{

#ifndef OMITBAD

void bad()
{
    long long * data;
    data = NULL; /* Initialize data */
    if(global_returns_t_or_f())
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            static long long data_buf[100];
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
            long long * data_buf = new long long[100];
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
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
   both branches use the GoodSource */
static void goodG2B()
{
    long long * data;
    data = NULL; /* Initialize data */
    if(global_returns_t_or_f())
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            long long * data_buf = new long long[100];
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
            long long * data_buf = new long long[100];
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
    delete [] data;
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_long_long_static_12; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif