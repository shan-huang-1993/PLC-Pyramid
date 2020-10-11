/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_54d.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sink:
 *    BadSink : Remove element from list
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _linked_list
{
    struct _linked_list *next;
    struct _linked_list *prev;
} linked_list;

typedef struct _bad_struct
{
    linked_list list;
} bad_struct;

static linked_list *prev, *next;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE123_Write_What_Where_Condition__fgets_54e_bad_sink(bad_struct data);

void CWE123_Write_What_Where_Condition__fgets_54d_bad_sink(bad_struct data)
{
    CWE123_Write_What_Where_Condition__fgets_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE123_Write_What_Where_Condition__fgets_54e_goodG2B_sink(bad_struct data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE123_Write_What_Where_Condition__fgets_54d_goodG2B_sink(bad_struct data)
{
    CWE123_Write_What_Where_Condition__fgets_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
