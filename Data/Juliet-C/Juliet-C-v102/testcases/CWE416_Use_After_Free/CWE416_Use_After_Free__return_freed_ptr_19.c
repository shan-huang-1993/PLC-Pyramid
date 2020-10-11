/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__return_freed_ptr_19.c
Label Definition File: CWE416_Use_After_Free__return_freed_ptr.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Sinks:
 *    GoodSink: Use a block of memory returned from a function
 *    BadSink : Use a block of memory returned from a function after it has been freed
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

static char * helper_bad(char * aString)
{
    size_t i = 0;
    size_t j;
    char * revString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        revString = (char *) malloc(i+1);
        for (j = 0; j < i; j++)
        {
            revString[j] = aString[i-j-1];
        }
        revString[i] = '\0';
        /* FLAW: Freeing a memory block and then returning a pointer to the freed memory */
        free(revString);
        return revString;
    }
    else
    {
        return NULL;
    }
}

static char * helper_good(char * aString)
{
    size_t i = 0;
    size_t j;
    char * revString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        revString = (char *) malloc(i+1);
        for (j = 0; j < i; j++)
        {
            revString[j] = aString[i-j-1];
        }
        revString[i] = '\0';
        /* FIX: Do not free the memory before returning */
        return revString;
    }
    else
    {
        return NULL;
    }
}

#ifndef OMITBAD

void CWE416_Use_After_Free__return_freed_ptr_19_bad()
{
    {
        /* Call the bad helper function */
        char * reversedString = helper_bad("BadSink");
        printLine(reversedString);
        /* free(reversedString);
         * This call to free() was removed because we want the tool to detect the use after free,
         * but we don't want that function to be free(). Essentially we want to avoid a double free */
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* Call the good helper function */
        char * reversedString = helper_good("GoodSink");
        printLine(reversedString);
        /* free(reversedString);
         * This call to free() was removed because we want the tool to detect the use after free,
         * but we don't want that function to be free(). Essentially we want to avoid a double free */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        /* Call the good helper function */
        char * reversedString = helper_good("GoodSink");
        printLine(reversedString);
        /* free(reversedString);
         * This call to free() was removed because we want the tool to detect the use after free,
         * but we don't want that function to be free(). Essentially we want to avoid a double free */
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* Call the bad helper function */
        char * reversedString = helper_bad("BadSink");
        printLine(reversedString);
        /* free(reversedString);
         * This call to free() was removed because we want the tool to detect the use after free,
         * but we don't want that function to be free(). Essentially we want to avoid a double free */
    }
}

void CWE416_Use_After_Free__return_freed_ptr_19_good()
{
    good1();
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
    CWE416_Use_After_Free__return_freed_ptr_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__return_freed_ptr_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
