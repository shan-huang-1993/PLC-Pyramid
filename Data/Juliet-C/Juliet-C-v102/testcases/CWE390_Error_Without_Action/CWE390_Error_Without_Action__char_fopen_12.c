/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_fopen_12.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    GoodSink: Check to see if fopen() failed, and handle errors properly
 *    BadSink : Check to see if fopen() failed, but fail to handle errors
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_fopen_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            FILE * file_ptr = fopen("file.txt", "w+");
            /* FLAW: Check to see if fopen() failed, but do nothing about it */
            if (file_ptr == NULL)
            {
                /* do nothing */
            }
            if (fputs("Write something to the file", stdout) == EOF)
            {
                printLine("fputs failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
    else
    {
        {
            FILE * file_ptr = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputs("Write something to the file", stdout) == EOF)
            {
                printLine("fputs failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            FILE * file_ptr = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputs("Write something to the file", stdout) == EOF)
            {
                printLine("fputs failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
    else
    {
        {
            FILE * file_ptr = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputs("Write something to the file", stdout) == EOF)
            {
                printLine("fputs failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
}

void CWE390_Error_Without_Action__char_fopen_12_good()
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
    CWE390_Error_Without_Action__char_fopen_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_fopen_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
