/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_67b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE665_Improper_Initialization__wchar_t_cat_67_struct_type
{
    wchar_t * a;
} CWE665_Improper_Initialization__wchar_t_cat_67_struct_type;

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_cat_67b_bad_sink(CWE665_Improper_Initialization__wchar_t_cat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, src);
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_cat_67b_goodG2B_sink(CWE665_Improper_Initialization__wchar_t_cat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, src);
        printWLine(data);
    }
}

#endif /* OMITGOOD */
