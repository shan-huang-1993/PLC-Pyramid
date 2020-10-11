/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_67b.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define WFOPEN _wfopen
#else
/*fopen is used on unix-based OSs */
# define WFOPEN fopen
#endif

typedef struct _CWE690_NULL_Deref_from_Return__wfopen_67_struct_type
{
    FILE * a;
} CWE690_NULL_Deref_from_Return__wfopen_67_struct_type;

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__wfopen_67b_bad_sink(CWE690_NULL_Deref_from_Return__wfopen_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__wfopen_67b_goodB2G_sink(CWE690_NULL_Deref_from_Return__wfopen_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITGOOD */
