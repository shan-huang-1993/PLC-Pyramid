/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    FILE * a;
    FILE * b;
} CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_union_type;

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_bad()
{
    FILE * data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_union_type my_union;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    my_union.a = data;
    {
        FILE * data = my_union.b;
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_union_type my_union;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    my_union.a = data;
    {
        FILE * data = my_union.b;
        /* FIX: If the file is still opened, close it */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
