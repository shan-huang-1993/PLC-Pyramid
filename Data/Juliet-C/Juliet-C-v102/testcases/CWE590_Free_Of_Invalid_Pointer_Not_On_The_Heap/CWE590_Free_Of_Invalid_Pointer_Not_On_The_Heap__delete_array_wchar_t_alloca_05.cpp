/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_alloca_05.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-05.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_alloca_05
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    if(static_t)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            wchar_t * data_buf = new wchar_t[100];
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            wchar_t * data_buf = new wchar_t[100];
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    if(static_t)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            wchar_t * data_buf = new wchar_t[100];
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = L'\0'; /* null terminate */
            data = data_buf;
        }
    }
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

void good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_alloca_05; // so that we can use good and bad easily

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
