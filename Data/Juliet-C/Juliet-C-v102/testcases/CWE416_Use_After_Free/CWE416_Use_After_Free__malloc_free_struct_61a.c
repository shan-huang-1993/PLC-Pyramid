/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_61a.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
twoints * CWE416_Use_After_Free__malloc_free_struct_61b_bad_source(twoints * data);

void CWE416_Use_After_Free__malloc_free_struct_61_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = CWE416_Use_After_Free__malloc_free_struct_61b_bad_source(data);
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
twoints * CWE416_Use_After_Free__malloc_free_struct_61b_goodG2B_source(twoints * data);

static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = CWE416_Use_After_Free__malloc_free_struct_61b_goodG2B_source(data);
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* goodB2G uses the BadSource with the GoodSink */
twoints * CWE416_Use_After_Free__malloc_free_struct_61b_goodB2G_source(twoints * data);

static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = CWE416_Use_After_Free__malloc_free_struct_61b_goodB2G_source(data);
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

void CWE416_Use_After_Free__malloc_free_struct_61_good()
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
    CWE416_Use_After_Free__malloc_free_struct_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
