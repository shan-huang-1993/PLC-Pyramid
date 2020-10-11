/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_15.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    GoodSink: Use CryptGenRandom() to generate a random number
 *    BadSink : Use rand() to generate a random number
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <windows.h>
# include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE338_Weak_PRNG__w32_15_bad()
{
    switch(6)
    {
    case 6:
    {
        /* FLAW: Use of rand() as a PRNG */
        int data = rand();
        printIntLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV hCryptProv;
        BYTE pbData[4];
        int data;
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0)) exit(1);
        /* FIX: Use of CryptGenRandom() as a more secure PRNG */
        if (!CryptGenRandom(hCryptProv, 4, pbData))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        CryptReleaseContext(hCryptProv, 0);
        data = (int)*pbData;
        printIntLine(data);
#endif
    }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: Use of rand() as a PRNG */
        int data = rand();
        printIntLine(data);
    }
    break;
    default:
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV hCryptProv;
        BYTE pbData[4];
        int data;
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0)) exit(1);
        /* FIX: Use of CryptGenRandom() as a more secure PRNG */
        if (!CryptGenRandom(hCryptProv, 4, pbData))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        CryptReleaseContext(hCryptProv, 0);
        data = (int)*pbData;
        printIntLine(data);
#endif
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV hCryptProv;
        BYTE pbData[4];
        int data;
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0)) exit(1);
        /* FIX: Use of CryptGenRandom() as a more secure PRNG */
        if (!CryptGenRandom(hCryptProv, 4, pbData))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        CryptReleaseContext(hCryptProv, 0);
        data = (int)*pbData;
        printIntLine(data);
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: Use of rand() as a PRNG */
        int data = rand();
        printIntLine(data);
    }
    }
}

void CWE338_Weak_PRNG__w32_15_good()
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
    CWE338_Weak_PRNG__w32_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE338_Weak_PRNG__w32_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
