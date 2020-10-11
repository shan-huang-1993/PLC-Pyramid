/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE366_Race_Condition_Within_A_Thread__int_byref_10.c
Label Definition File: CWE366_Race_Condition_Within_A_Thread.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 366 Race Condition Within a Thread
 * Sinks: int_byref
 *    GoodSink: Acquire a lock before conducting operations
 *    BadSink : Do not acquire a lock before conducting operations
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

#define N_ITERS 1000000

static std_thread_lock g_good_lock = NULL;

static void helper_bad(void *args)
{
    int *p_val = (int*)args;
    int i;
    /* FLAW: incrementing an integer is not guaranteed to occur atomically;
     * therefore this operation may not function as intended in multi-threaded
     * programs
     */
    for (i = 0; i < N_ITERS; i++)
    {
        *p_val = *p_val + 1;
    }
}

static void helper_good(void *args)
{
    int *p_val = (int *)args;
    int i;
    /* FIX: acquire a lock before conducting operations that need to occur
     * atomically, and release afterwards
     */
    std_thread_lock_acquire(g_good_lock);
    for (i = 0; i < N_ITERS; i++)
    {
        *p_val = *p_val + 1;
    }
    std_thread_lock_release(g_good_lock);
}

#ifndef OMITBAD

void CWE366_Race_Condition_Within_A_Thread__int_byref_10_bad()
{
    if(global_t)
    {
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_create(helper_bad, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_bad, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            printIntLine(val);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_lock_create(&g_good_lock))
            {
                return;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            std_thread_lock_destroy(g_good_lock);
            printIntLine(val);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_f) instead of if(global_t) */
static void good1()
{
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_create(helper_bad, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_bad, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            printIntLine(val);
        }
    }
    else
    {
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_lock_create(&g_good_lock))
            {
                return;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            std_thread_lock_destroy(g_good_lock);
            printIntLine(val);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_t)
    {
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_lock_create(&g_good_lock))
            {
                return;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_good, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            std_thread_lock_destroy(g_good_lock);
            printIntLine(val);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            std_thread thread_a = NULL;
            std_thread thread_b = NULL;
            int val;
            val = 0;
            if (!std_thread_create(helper_bad, (void*)&val, &thread_a))
            {
                thread_a = NULL;
            }
            if (!std_thread_create(helper_bad, (void*)&val, &thread_b))
            {
                thread_b = NULL;
            }
            if (thread_a && std_thread_join(thread_a)) std_thread_destroy(thread_a);
            if (thread_b && std_thread_join(thread_b)) std_thread_destroy(thread_b);
            printIntLine(val);
        }
    }
}

void CWE366_Race_Condition_Within_A_Thread__int_byref_10_good()
{
    good1();
    good2();
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
    CWE366_Race_Condition_Within_A_Thread__int_byref_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE366_Race_Condition_Within_A_Thread__int_byref_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
