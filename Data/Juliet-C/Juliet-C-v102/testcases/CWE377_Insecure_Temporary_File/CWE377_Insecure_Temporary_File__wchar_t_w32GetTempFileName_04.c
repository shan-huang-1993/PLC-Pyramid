/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_04.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameW(), insecurely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameW(), insecurely
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
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

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_04_bad()
{
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_04_good()
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
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
