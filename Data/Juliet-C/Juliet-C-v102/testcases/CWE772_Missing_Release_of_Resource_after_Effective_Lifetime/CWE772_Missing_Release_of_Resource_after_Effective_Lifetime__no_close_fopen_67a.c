/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67a.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-67a.tmpl.c
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

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_bad_sink(CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_bad()
{
    FILE * data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    my_struct.a = data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_goodB2G_sink(CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct);

static void goodB2G()
{
    FILE * data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_struct_type my_struct;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    my_struct.a = data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67b_goodB2G_sink(my_struct);
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_good()
{
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
