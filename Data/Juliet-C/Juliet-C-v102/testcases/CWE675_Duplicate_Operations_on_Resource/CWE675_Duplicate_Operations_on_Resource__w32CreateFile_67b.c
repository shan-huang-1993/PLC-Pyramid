/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_struct_type
{
    HANDLE a;
} CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_struct_type;

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b_bad_sink(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_struct_type my_struct)
{
    HANDLE data = my_struct.a;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b_goodG2B_sink(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_struct_type my_struct)
{
    HANDLE data = my_struct.a;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b_goodB2G_sink(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_struct_type my_struct)
{
    HANDLE data = my_struct.a;
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */
