/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_close_67b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

typedef struct _CWE404_Improper_Resource_Shutdown__fopen_close_67_struct_type
{
    FILE * a;
} CWE404_Improper_Resource_Shutdown__fopen_close_67_struct_type;

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__fopen_close_67b_bad_sink(CWE404_Improper_Resource_Shutdown__fopen_close_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using close() instead of fclose() */
        CLOSE((int)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__fopen_close_67b_goodB2G_sink(CWE404_Improper_Resource_Shutdown__fopen_close_67_struct_type my_struct)
{
    FILE * data = my_struct.a;
    if (data != NULL)
    {
        /* FIX: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITGOOD */
