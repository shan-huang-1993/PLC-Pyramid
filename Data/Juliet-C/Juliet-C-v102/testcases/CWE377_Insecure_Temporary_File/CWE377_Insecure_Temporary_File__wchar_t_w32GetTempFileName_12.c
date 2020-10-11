/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_12.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameW(), insecurely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameW(), insecurely
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
# define FOPEN _wfopen
#else
# define OPEN wopen
# define CLOSE close
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            FILE * tmp;
            if (GetTempFileNameW(L".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL) fclose(tmp);
        }
    }
    else
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fd;
            if (GetTempFileNameW(L".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file opened successfully");
                CLOSE(fd);
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
            wchar_t filename[MAX_PATH] = L"";
            int fd;
            if (GetTempFileNameW(L".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file opened successfully");
                CLOSE(fd);
            }
        }
    }
    else
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fd;
            if (GetTempFileNameW(L".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file opened successfully");
                CLOSE(fd);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_12_good()
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
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
