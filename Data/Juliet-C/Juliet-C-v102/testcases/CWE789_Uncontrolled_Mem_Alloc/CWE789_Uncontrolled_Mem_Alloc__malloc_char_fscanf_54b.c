/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING "hello"

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_bad_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54b_bad_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_goodG2B_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54b_goodG2B_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_goodB2G_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54b_goodB2G_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
