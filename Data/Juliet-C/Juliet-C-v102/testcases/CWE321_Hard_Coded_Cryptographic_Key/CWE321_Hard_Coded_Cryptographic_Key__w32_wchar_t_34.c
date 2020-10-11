/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sinks:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#define CRYPTOKEY L"Hardcoded"

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#endif

typedef union
{
    wchar_t * a;
    wchar_t * b;
} CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_union_type;

#ifndef OMITBAD

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_bad()
{
    wchar_t * cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_union_type my_union;
    wchar_t cryptokey_buf[100] = L"";
    cryptokey = cryptokey_buf;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    wcscpy(cryptokey, CRYPTOKEY);
    my_union.a = cryptokey;
    {
        wchar_t * cryptokey = my_union.b;
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HCRYPTPROV cryptoprov;
            HCRYPTKEY key;
            HCRYPTHASH hash;
            wchar_t toBeEncrypted[100] = L"String to be encrypted"; /* buffer should be larger than string to have room for IV and padding */
            DWORD toBeEncryptedLen = wcslen(toBeEncrypted)*sizeof(wchar_t);
            /* Try to get a context with and without a new key set */
            if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
            {
                if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
                {
                    printLine("Error in acquiring cryptographic context");
                    exit(1);
                }
            }
            /* Create Hash handle */
            if(!CryptCreateHash(cryptoprov, CALG_SHA1, 0, 0, &hash))
            {
                printLine("Error in creating hash");
                exit(1);
            }
            /* Hash the cryptokey */
            if(!CryptHashData(hash, (BYTE *) cryptokey, wcslen(cryptokey)*sizeof(wchar_t), 0))
            {
                printLine("Error in hashing cryptokey");
                exit(1);
            }
            /* Derive a Triple-DES key from the Hashed cryptokey */
            if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
            {
                printLine("Error in CryptDeriveKey");
                exit(1);
            }
            /* POTENTIAL FLAW: Possibly using a hardcoded crypto key */
            /* Use the derived key to encrypt something */
            if(!CryptEncrypt(key, (HCRYPTHASH)NULL, 1, 0, (BYTE *)toBeEncrypted, &toBeEncryptedLen, sizeof(toBeEncrypted)))
            {
                printLine("Error in CryptEncryptData");
                exit(1);
            }
            /* use encrypted block */
            printWLine(toBeEncrypted);
#endif
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_union_type my_union;
    wchar_t cryptokey_buf[100] = L"";
    cryptokey = cryptokey_buf;
    {
        size_t cryptokey_len = wcslen(cryptokey);
        /* if there is room in cryptokey, read into it from the console */
        if(100-cryptokey_len > 1)
        {
            /* FIX: Obtain the hash input from the console */
            fgetws(cryptokey+cryptokey_len, (int)(100-cryptokey_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            cryptokey_len = wcslen(cryptokey);
            if (cryptokey_len > 0)
            {
                cryptokey[cryptokey_len-1] = L'\0';
            }
        }
    }
    my_union.a = cryptokey;
    {
        wchar_t * cryptokey = my_union.b;
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HCRYPTPROV cryptoprov;
            HCRYPTKEY key;
            HCRYPTHASH hash;
            wchar_t toBeEncrypted[100] = L"String to be encrypted"; /* buffer should be larger than string to have room for IV and padding */
            DWORD toBeEncryptedLen = wcslen(toBeEncrypted)*sizeof(wchar_t);
            /* Try to get a context with and without a new key set */
            if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
            {
                if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
                {
                    printLine("Error in acquiring cryptographic context");
                    exit(1);
                }
            }
            /* Create Hash handle */
            if(!CryptCreateHash(cryptoprov, CALG_SHA1, 0, 0, &hash))
            {
                printLine("Error in creating hash");
                exit(1);
            }
            /* Hash the cryptokey */
            if(!CryptHashData(hash, (BYTE *) cryptokey, wcslen(cryptokey)*sizeof(wchar_t), 0))
            {
                printLine("Error in hashing cryptokey");
                exit(1);
            }
            /* Derive a Triple-DES key from the Hashed cryptokey */
            if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
            {
                printLine("Error in CryptDeriveKey");
                exit(1);
            }
            /* POTENTIAL FLAW: Possibly using a hardcoded crypto key */
            /* Use the derived key to encrypt something */
            if(!CryptEncrypt(key, (HCRYPTHASH)NULL, 1, 0, (BYTE *)toBeEncrypted, &toBeEncryptedLen, sizeof(toBeEncrypted)))
            {
                printLine("Error in CryptEncryptData");
                exit(1);
            }
            /* use encrypted block */
            printWLine(toBeEncrypted);
#endif
        }
    }
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_good()
{
    goodG2B();
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
