/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.string.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: snprintf
 *    BadSink : Copy string to data using snwprintf
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type
{
    wchar_t * a;
} CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67b_bad_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type my_struct);

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_bad()
{
    wchar_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type my_struct;
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    data[0] = L'\0'; /* null terminate */
    my_struct.a = data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67b_goodG2B_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_struct_type my_struct;
    data = NULL;
    /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    data[0] = L'\0'; /* null terminate */
    my_struct.a = data;
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67b_goodG2B_sink(my_struct);
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_good()
{
    goodG2B();
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
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_snprintf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
