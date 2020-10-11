/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_bad_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_goodG2B_sink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_goodB2G_sink(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51b_goodB2G_sink(data);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif