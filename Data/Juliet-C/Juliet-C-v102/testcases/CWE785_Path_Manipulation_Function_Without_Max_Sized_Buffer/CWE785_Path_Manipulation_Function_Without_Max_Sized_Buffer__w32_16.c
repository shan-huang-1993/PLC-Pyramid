/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_16.c
Label Definition File: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 785 Path Manipulation Function Without Max Sized Buffer
 * Sinks:
 *    GoodSink: Ensure the path parameter is MAX_PATH
 *    BadSink : Use PathAppend() with a buffer that is less than MAX_PATH
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32 /* this is WIN32 specific */
#include <windows.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi")

#define BAD_SZ (MAX_PATH / 2) /* maintenance note: must be < MAX_PATH in order for 'bad' to be 'bad' */
#endif

#ifndef OMITBAD

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_16_bad()
{
    while(1)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char path[BAD_SZ];
            DWORD length;
            length = GetCurrentDirectoryA(BAD_SZ, path);
            if (length == 0 || length >= BAD_SZ) exit(1); /* failure conditions for this API call */
            /* FLAW: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printSizeTLine(strlen(path));
            printIntLine(BAD_SZ);
            printLine(path);
#endif /* _WIN32 */
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            /* FIX: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH) exit(1); /* failure conditions for this API call */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printLine(path);
#endif /* _WIN32 */
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char path[BAD_SZ];
            DWORD length;
            length = GetCurrentDirectoryA(BAD_SZ, path);
            if (length == 0 || length >= BAD_SZ) exit(1); /* failure conditions for this API call */
            /* FLAW: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printSizeTLine(strlen(path));
            printIntLine(BAD_SZ);
            printLine(path);
#endif /* _WIN32 */
        }
        break;
    }
    while(1)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            /* FIX: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH) exit(1); /* failure conditions for this API call */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printLine(path);
#endif /* _WIN32 */
        }
        break;
    }
}

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_16_good()
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
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
