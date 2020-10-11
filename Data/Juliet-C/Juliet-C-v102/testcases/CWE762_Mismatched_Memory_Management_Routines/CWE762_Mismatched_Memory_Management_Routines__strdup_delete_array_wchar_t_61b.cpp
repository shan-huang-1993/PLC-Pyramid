/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_61
{

#ifndef OMITBAD

wchar_t * bad_source(wchar_t * data)
{
    {
        wchar_t mystring[] = L"mystring";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = wcsdup(mystring);
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * goodG2B_source(wchar_t * data)
{
    /* FIX: Allocate memory from the heap using new [] */
    data = new wchar_t[100];
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
wchar_t * goodB2G_source(wchar_t * data)
{
    {
        wchar_t mystring[] = L"mystring";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = wcsdup(mystring);
    }
    return data;
}

#endif /* OMITGOOD */

} // close namespace
