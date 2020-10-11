/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

#ifndef OMITBAD

int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_bad_source(int data)
{
    data = RAND32();
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_goodG2B_source(int data)
{
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_61b_goodB2G_source(int data)
{
    data = RAND32();
    return data;
}

#endif /* OMITGOOD */
