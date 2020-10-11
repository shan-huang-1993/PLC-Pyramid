/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_64b.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-64b.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sinks:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
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

#ifndef OMITBAD

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_64b_bad_sink(void * void_cryptokey_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    wchar_t * * cryptokey_ptr = (wchar_t * *)void_cryptokey_ptr;
    /* dereference cryptokey_ptr into cryptokey */
    wchar_t * cryptokey = (*cryptokey_ptr);
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_64b_goodG2B_sink(void * void_cryptokey_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    wchar_t * * cryptokey_ptr = (wchar_t * *)void_cryptokey_ptr;
    /* dereference cryptokey_ptr into cryptokey */
    wchar_t * cryptokey = (*cryptokey_ptr);
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

#endif /* OMITGOOD */
