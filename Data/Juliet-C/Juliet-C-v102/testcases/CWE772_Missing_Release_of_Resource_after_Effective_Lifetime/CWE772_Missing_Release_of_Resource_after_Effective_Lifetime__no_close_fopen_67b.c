/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type
{
    FILE * a;
} CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type;

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_bad_sink(CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_goodB2G_sink(CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    /* FIX: If the file is still opened, close it */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITGOOD */
