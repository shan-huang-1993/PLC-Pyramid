/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

typedef struct _CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67_struct_type
{
    wchar_t * a;
} CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67_struct_type;

#ifndef OMITBAD

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67b_bad_sink(CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            v = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                v++; /* avoid a dead/empty code block issue */
            }
            printIntLine(v);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67b_goodG2B_sink(CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            v = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                v++; /* avoid a dead/empty code block issue */
            }
            printIntLine(v);
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67b_goodB2G_sink(CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* FIX: limit loop iteration counts */
            if (n < MAX_LOOP)
            {
                v = 0;
                for (i = 0; i < n; i++)
                {
                    /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                    v++; /* avoid a dead/empty code block issue */
                }
                printIntLine(v);
            }
        }
    }
}

#endif /* OMITGOOD */
