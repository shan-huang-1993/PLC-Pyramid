/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_13.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__new.label.xml
Template File: sources-sinks-13.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_13
{

#ifndef OMITBAD

void bad()
{
    twoints * data;
    data = new twoints[10];
    if(global_const_five==5)
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
    }
    if(global_const_five==5)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_const_five==5 to global_const_five!=5 */
static void goodB2G1()
{
    twoints * data;
    data = new twoints[10];
    if(global_const_five==5)
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
    }
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
    else
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoints * data;
    data = new twoints[10];
    if(global_const_five==5)
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
    }
    if(global_const_five==5)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_const_five==5 to global_const_five!=5 */
static void goodG2B1()
{
    twoints * data;
    data = new twoints[10];
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
    }
    if(global_const_five==5)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoints * data;
    data = new twoints[10];
    if(global_const_five==5)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(global_const_five==5)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i].a = i;
                data[i].b = i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].a);
                printIntLine(data[i].b);
            }
        }
        /* deallocate the memory */
        delete [] data;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
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

using namespace CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_13; // so that we can use good and bad easily

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
