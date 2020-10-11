/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_alloca_16.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_alloca_16
{

#ifndef OMITBAD

void bad()
{
    twoints * data;
    data = NULL; /* Initialize data */
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            twoints * data_buf = new twoints[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i].a = 1;
                    data_buf[i].b = 1;
                }
            }
            data = data_buf;
        }
        break;
    }
    while(1)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            twoints * data_buf = (twoints *)ALLOCA(100*sizeof(twoints));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i].a = 1;
                    data_buf[i].b = 1;
                }
            }
            data = data_buf;
        }
        break;
    }
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    twoints * data;
    data = NULL; /* Initialize data */
    while(1)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            twoints * data_buf = new twoints[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i].a = 1;
                    data_buf[i].b = 1;
                }
            }
            data = data_buf;
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            twoints * data_buf = (twoints *)ALLOCA(100*sizeof(twoints));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i].a = 1;
                    data_buf[i].b = 1;
                }
            }
            data = data_buf;
        }
        break;
    }
    printStructLine(&data[0]);
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

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_alloca_16; // so that we can use good and bad easily

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
