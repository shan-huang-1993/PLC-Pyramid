/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fixed Large, fixed value
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_bad_data;
int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_goodG2B_data;
int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_bad_sink();

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_bad_data = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_goodG2B_sink();
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_goodG2B_data = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_goodB2G_data = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68b_goodB2G_sink();
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_good()
{
    goodG2B();
    goodB2G();
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
