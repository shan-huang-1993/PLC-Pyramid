/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE364_Signal_Handler_Race_Condition__basic_03.c
Label Definition File: CWE364_Signal_Handler_Race_Condition__basic.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 364 Signal Handler Race Condition
 * Sinks:
 *    GoodSink: Disable the signal handler while performing non-atomic operations
 *    BadSink : Do not disable the signal handler while performing non-atomic operations
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <signal.h>

typedef struct _CWE364_Signal_Handler_Race_Condition__basic_03_global
{
    sig_atomic_t val;
} CWE364_Signal_Handler_Race_Condition__basic_03_global_t;

CWE364_Signal_Handler_Race_Condition__basic_03_global_t *CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
CWE364_Signal_Handler_Race_Condition__basic_03_global_t *CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = NULL;

static void helper_bad(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad->val = 2;
    }
}

static void helper_good(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good->val = 2;
    }
}

#ifndef OMITBAD

void CWE364_Signal_Handler_Race_Condition__basic_03_bad()
{
    if(5==5)
    {
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_bad);
            /* FLAW: This test, free, and set operation is not atomic, so if signal
             * delivery occurs (for example) between the free and setting to NULL,
             * the signal handler could corrupt the heap, cause an access violation,
             * etc
             *
             * Technically, "CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = 0" is not atomic on certain theoretical computer
             * systems that don't actually exist, but this should trigger on
             * theoretical as well as actual computer systems.
             */
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = 0;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_good);
            /* FIX: In this instance, the fix is to temporarily disable the signal
             * handler while performing non-atomic operations.  Another way would
             * be to use sigprocmask or sigvec, or to restructure the signal handler
             * to operate in a safe manner.
             */
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = NULL;
            }
            signal(SIGINT, helper_good);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_bad);
            /* FLAW: This test, free, and set operation is not atomic, so if signal
             * delivery occurs (for example) between the free and setting to NULL,
             * the signal handler could corrupt the heap, cause an access violation,
             * etc
             *
             * Technically, "CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = 0" is not atomic on certain theoretical computer
             * systems that don't actually exist, but this should trigger on
             * theoretical as well as actual computer systems.
             */
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
        }
    }
    else
    {
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = 0;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_good);
            /* FIX: In this instance, the fix is to temporarily disable the signal
             * handler while performing non-atomic operations.  Another way would
             * be to use sigprocmask or sigvec, or to restructure the signal handler
             * to operate in a safe manner.
             */
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = NULL;
            }
            signal(SIGINT, helper_good);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = 0;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_good);
            /* FIX: In this instance, the fix is to temporarily disable the signal
             * handler while performing non-atomic operations.  Another way would
             * be to use sigprocmask or sigvec, or to restructure the signal handler
             * to operate in a safe manner.
             */
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_good = NULL;
            }
            signal(SIGINT, helper_good);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            CWE364_Signal_Handler_Race_Condition__basic_03_global_t *global = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
            global = (CWE364_Signal_Handler_Race_Condition__basic_03_global_t*)malloc(sizeof(CWE364_Signal_Handler_Race_Condition__basic_03_global_t));
            /* INCIDENTAL - No check for NULL on malloc() */
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = global;
            CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helper_bad);
            /* FLAW: This test, free, and set operation is not atomic, so if signal
             * delivery occurs (for example) between the free and setting to NULL,
             * the signal handler could corrupt the heap, cause an access violation,
             * etc
             *
             * Technically, "CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = 0" is not atomic on certain theoretical computer
             * systems that don't actually exist, but this should trigger on
             * theoretical as well as actual computer systems.
             */
            if (CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad);
                CWE364_Signal_Handler_Race_Condition__basic_03_g_cur_bad = NULL;
            }
        }
    }
}

void CWE364_Signal_Handler_Race_Condition__basic_03_good()
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
    CWE364_Signal_Handler_Race_Condition__basic_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE364_Signal_Handler_Race_Condition__basic_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
