/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_67a.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE123_Write_What_Where_Condition__fgets_67_struct_type
{
    bad_struct a;
} CWE123_Write_What_Where_Condition__fgets_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE123_Write_What_Where_Condition__fgets_67b_bad_sink(CWE123_Write_What_Where_Condition__fgets_67_struct_type my_struct);

void CWE123_Write_What_Where_Condition__fgets_67_bad()
{
    bad_struct data;
    CWE123_Write_What_Where_Condition__fgets_67_struct_type my_struct;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    /* FLAW: overwrite linked list pointers with user data */
    fgets((char*)&data, sizeof(data), stdin);
    my_struct.a = data;
    CWE123_Write_What_Where_Condition__fgets_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE123_Write_What_Where_Condition__fgets_67b_goodG2B_sink(CWE123_Write_What_Where_Condition__fgets_67_struct_type my_struct);

static void goodG2B()
{
    bad_struct data;
    CWE123_Write_What_Where_Condition__fgets_67_struct_type my_struct;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    /* FIX: don't overwrite linked list pointers */
    ; /* empty statement needed by some flow variants */
    my_struct.a = data;
    CWE123_Write_What_Where_Condition__fgets_67b_goodG2B_sink(my_struct);
}

void CWE123_Write_What_Where_Condition__fgets_67_good()
{
    goodG2B();
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
    CWE123_Write_What_Where_Condition__fgets_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE123_Write_What_Where_Condition__fgets_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
