/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromFile_w32CreateFile_02.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-02.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#include <windows.h>

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromFile_w32CreateFile_02_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    if(1)
    {
        {
            /* Read input from a file */
            size_t data_len = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if(FILENAME_MAX-data_len > 1)
            {
                pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
                if (pFile != NULL)
                {
                    fgetws(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                    fclose(pFile);
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        /* FIX: Full path and file name */
        wcscpy(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        wcscpy(data, L"/tmp/file.txt");
#endif
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the 1 to 0 */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from a file */
            size_t data_len = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if(FILENAME_MAX-data_len > 1)
            {
                pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
                if (pFile != NULL)
                {
                    fgetws(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                    fclose(pFile);
                }
            }
        }
    }
    else
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        wcscpy(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        wcscpy(data, L"/tmp/file.txt");
#endif
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    if(1)
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        wcscpy(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        wcscpy(data, L"/tmp/file.txt");
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from a file */
            size_t data_len = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if(FILENAME_MAX-data_len > 1)
            {
                pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
                if (pFile != NULL)
                {
                    fgetws(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                    fclose(pFile);
                }
            }
        }
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

void CWE36_Absolute_Path_Traversal__wchar_t_fromFile_w32CreateFile_02_good()
{
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
    CWE36_Absolute_Path_Traversal__wchar_t_fromFile_w32CreateFile_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__wchar_t_fromFile_w32CreateFile_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
