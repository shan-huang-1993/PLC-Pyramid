/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fixed Large, fixed value
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

typedef struct _CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type
{
    int a;
} CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_bad_sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_bad()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
    my_struct.a = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_goodG2B_sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    my_struct.a = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_goodB2G_sink(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct);

static void goodB2G()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use a relatively large number for memory allocation */
    data = 10000;
    my_struct.a = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67b_goodB2G_sink(my_struct);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fixed_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
