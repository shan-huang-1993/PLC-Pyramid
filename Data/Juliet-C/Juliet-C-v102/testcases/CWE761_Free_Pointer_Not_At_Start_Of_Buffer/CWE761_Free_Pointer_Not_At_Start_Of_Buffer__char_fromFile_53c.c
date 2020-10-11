/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53c.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fromFile Read input from a file
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'
#define BAD_SRC_FIXED "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53d_bad_sink(char * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53c_bad_sink(char * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53d_goodB2G_sink(char * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53c_goodB2G_sink(char * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromFile_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
