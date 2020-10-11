/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_09.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef OMITBAD

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_09_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_const_t)
    {
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to a number less than MAX_LOOP */
        wcscpy(data, L"15");
    }
    if(global_const_t)
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_const_t to global_const_f */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_const_t)
    {
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to a number less than MAX_LOOP */
        wcscpy(data, L"15");
    }
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    else
    {
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_const_t)
    {
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to a number less than MAX_LOOP */
        wcscpy(data, L"15");
    }
    if(global_const_t)
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B1() - use goodsource and badsink by changing the first global_const_t to global_const_f */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
    }
    else
    {
        /* FIX: Set data to a number less than MAX_LOOP */
        wcscpy(data, L"15");
    }
    if(global_const_t)
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_const_t)
    {
        /* FIX: Set data to a number less than MAX_LOOP */
        wcscpy(data, L"15");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
    }
    if(global_const_t)
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
