/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67b.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fromConsole Read input from the console
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

typedef struct _CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67_struct_type
{
    char * a;
} CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67_struct_type;

#ifndef OMITBAD

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67b_bad_sink(CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* FLAW: We are incrementing the pointer in the loop - this will cause us to free the
     * memory block not at the start of the buffer */
    for (; *data != '\0'; data++)
    {
        if (*data == SEARCH_CHAR)
        {
            printLine("We have a match!");
            break;
        }
    }
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67b_goodB2G_sink(CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fromConsole_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        size_t i;
        /* FIX: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < strlen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITGOOD */
