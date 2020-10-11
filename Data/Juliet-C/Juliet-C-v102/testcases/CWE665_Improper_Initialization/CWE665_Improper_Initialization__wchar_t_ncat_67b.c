/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_67b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE665_Improper_Initialization__wchar_t_ncat_67_struct_type
{
    wchar_t * a;
} CWE665_Improper_Initialization__wchar_t_ncat_67_struct_type;

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_ncat_67b_bad_sink(CWE665_Improper_Initialization__wchar_t_ncat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        size_t src_len;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        src_len = wcslen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, src, src_len);
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_ncat_67b_goodG2B_sink(CWE665_Improper_Initialization__wchar_t_ncat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        size_t src_len;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        src_len = wcslen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, src, src_len);
        printWLine(data);
    }
}

#endif /* OMITGOOD */
