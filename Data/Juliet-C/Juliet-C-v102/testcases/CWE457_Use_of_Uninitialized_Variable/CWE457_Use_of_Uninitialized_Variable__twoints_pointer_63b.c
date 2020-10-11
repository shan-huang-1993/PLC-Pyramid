/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twoints_pointer_63b.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_63b_bad_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    printIntLine(data->a);
    printIntLine(data->b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_63b_goodG2B_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    printIntLine(data->a);
    printIntLine(data->b);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_63b_goodB2G_sink(twoints * * data_ptr)
{
    twoints * data = *data_ptr;
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
}

#endif /* OMITGOOD */
