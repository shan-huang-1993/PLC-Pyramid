/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54d.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54e_bad_sink(int data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54d_bad_sink(int data)
{
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54e_goodB2G_sink(int data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54d_goodB2G_sink(int data)
{
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
