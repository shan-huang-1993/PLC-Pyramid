/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_fixed_62b.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fixed Large, fixed value
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_fixed_62
{

#ifndef OMITBAD

void bad_source(int &data)
{
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(int &data)
{
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(int &data)
{
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
}

#endif /* OMITGOOD */

} // close namespace
