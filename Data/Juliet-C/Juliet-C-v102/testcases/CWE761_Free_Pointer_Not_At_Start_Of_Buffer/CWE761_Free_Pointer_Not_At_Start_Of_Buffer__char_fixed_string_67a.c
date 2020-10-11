/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67a.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'
#define BAD_SRC_FIXED "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

typedef struct _CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type
{
    char * a;
} CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67b_bad_sink(CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type my_struct);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_bad()
{
    char * data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type my_struct;
    data = (char *)malloc(100*sizeof(char));
    data[0] = '\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    my_struct.a = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67b_goodB2G_sink(CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type my_struct);

static void goodB2G()
{
    char * data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_struct_type my_struct;
    data = (char *)malloc(100*sizeof(char));
    data[0] = '\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    my_struct.a = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67b_goodB2G_sink(my_struct);
}

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_good()
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
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
