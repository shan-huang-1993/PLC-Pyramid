/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66a.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR L'S'
#define BAD_SRC_FIXED L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66b_bad_sink(wchar_t * data_array[]);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66_bad()
{
    wchar_t * data;
    wchar_t * data_array[5];
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    data[0] = L'\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SRC_FIXED);
    /* put data in array */
    data_array[2] = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66b_goodB2G_sink(wchar_t * data_array[]);

static void goodB2G()
{
    wchar_t * data;
    wchar_t * data_array[5];
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    data[0] = L'\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SRC_FIXED);
    data_array[2] = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66b_goodB2G_sink(data_array);
}

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66_good()
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
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_fixed_string_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
