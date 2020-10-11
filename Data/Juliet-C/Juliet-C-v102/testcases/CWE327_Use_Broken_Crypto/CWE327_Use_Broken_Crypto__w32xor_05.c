/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE327_Use_Broken_Crypto__w32xor_05.c
Label Definition File: CWE327_Use_Broken_Crypto.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 327 Use of a Broken or Risky Cryptographic Algorithm
 * Sinks: w32xor
 *    GoodSink: Use Triple-DES for decryption
 *    BadSink : Decrypt the block by XORing with the provided key
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#define BLOCK_SZ 1024
#define ASCII_KEY_SZ 64 /* since the key is ASCII and potentially not all 8-bits, ensure it is sufficiently large */
#define ASCII_KEY_WITH_PADDING_SZ (ASCII_KEY_SZ + 3) /* add space for null terminator, carriage return, newline */
#define RC4_STATE_SZ 256
#define RC4_DISCARD_SZ 3072 /* since the first N bytes of RC4 are heavily biased */

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE327_Use_Broken_Crypto__w32xor_05_bad()
{
    if(static_t)
    {
        {
            FILE *file;
            /* this name may provide a "hint" to static scanners that we intend for this to be "encrypted" */
            char encrypted_block[BLOCK_SZ+1];
            char decrypted_block[BLOCK_SZ+1];
            char ascii_key[ASCII_KEY_WITH_PADDING_SZ];
            char *replace;
            size_t i, j, key_sz;
            printLine("Input key: ");
            if (fgets(ascii_key, ASCII_KEY_WITH_PADDING_SZ, stdin) == NULL)
            {
                exit(1);
            }
            replace = strchr(ascii_key, '\r');
            if (replace) *replace = '\0';
            replace = strchr(ascii_key, '\n');
            if (replace) *replace = '\0';
            /* we require a key with sufficient entropy (128 bits)
             * (this also assumes the key was randomly generated)
             */
            key_sz = strlen(ascii_key);
            if (key_sz < ASCII_KEY_SZ) exit(1);
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(encrypted_block, sizeof(char), BLOCK_SZ, file) != BLOCK_SZ)
            {
                fclose(file);
                exit(1);
            }
            encrypted_block[BLOCK_SZ] = '\0';
            decrypted_block[BLOCK_SZ] = '\0';
            /* FLAW: "decrypt" the block by XORing with the provided key */
            for (i = 0, j = 0; i < BLOCK_SZ; i++, j++)
            {
                if (j == key_sz) j = 0;
                decrypted_block[i] = encrypted_block[i] ^ ascii_key[j];
            }
            printLine(decrypted_block);
            fclose(file);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            FILE *file;
            HCRYPTPROV cryptoprov;
            HCRYPTKEY key;
            HCRYPTHASH hash;
            char password[100];
            size_t password_len;
            char toBeDecrypted[100];
            DWORD toBeDecryptedLen = sizeof(toBeDecrypted)-1;
            /* Read the password from the console */
            printLine("Enter the password: ");
            fgets(password, 100, stdin);
            /* The next 3 lines remove the carriage return from the string that is
            * inserted by fgets() */
            password_len = strlen(password);
            if (password_len > 0)
            {
                password[password_len-1] = '\0';
            }
            /* Read the data to be decrypted from a file */
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(toBeDecrypted, sizeof(char), 100, file) != 100)
            {
                fclose(file);
                exit(1);
            }
            toBeDecrypted[99] = '\0';
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
            /* Hash the password */
            if(!CryptHashData(hash, (BYTE *) password, password_len, 0))
            {
                printLine("Error in hashing password");
                exit(1);
            }
            /* Derive a Triple-DES key from the Hashed password */
            if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
            {
                printLine("Error in CryptDeriveKey");
                exit(1);
            }
            /* FIX: Decrypt using Triple-DES */
            if(!CryptDecrypt(key, 0, 1, 0, (BYTE *)toBeDecrypted, &toBeDecryptedLen))
            {
                printLine("Error in decryption");
                exit(1);
            }
            printLine(toBeDecrypted);
            /* Cleanup */
            CryptReleaseContext(cryptoprov,0);
            CryptDestroyHash(hash);
            CryptDestroyKey(key);
            fclose(file);
#endif
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *file;
            /* this name may provide a "hint" to static scanners that we intend for this to be "encrypted" */
            char encrypted_block[BLOCK_SZ+1];
            char decrypted_block[BLOCK_SZ+1];
            char ascii_key[ASCII_KEY_WITH_PADDING_SZ];
            char *replace;
            size_t i, j, key_sz;
            printLine("Input key: ");
            if (fgets(ascii_key, ASCII_KEY_WITH_PADDING_SZ, stdin) == NULL)
            {
                exit(1);
            }
            replace = strchr(ascii_key, '\r');
            if (replace) *replace = '\0';
            replace = strchr(ascii_key, '\n');
            if (replace) *replace = '\0';
            /* we require a key with sufficient entropy (128 bits)
             * (this also assumes the key was randomly generated)
             */
            key_sz = strlen(ascii_key);
            if (key_sz < ASCII_KEY_SZ) exit(1);
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(encrypted_block, sizeof(char), BLOCK_SZ, file) != BLOCK_SZ)
            {
                fclose(file);
                exit(1);
            }
            encrypted_block[BLOCK_SZ] = '\0';
            decrypted_block[BLOCK_SZ] = '\0';
            /* FLAW: "decrypt" the block by XORing with the provided key */
            for (i = 0, j = 0; i < BLOCK_SZ; i++, j++)
            {
                if (j == key_sz) j = 0;
                decrypted_block[i] = encrypted_block[i] ^ ascii_key[j];
            }
            printLine(decrypted_block);
            fclose(file);
        }
    }
    else
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            FILE *file;
            HCRYPTPROV cryptoprov;
            HCRYPTKEY key;
            HCRYPTHASH hash;
            char password[100];
            size_t password_len;
            char toBeDecrypted[100];
            DWORD toBeDecryptedLen = sizeof(toBeDecrypted)-1;
            /* Read the password from the console */
            printLine("Enter the password: ");
            fgets(password, 100, stdin);
            /* The next 3 lines remove the carriage return from the string that is
            * inserted by fgets() */
            password_len = strlen(password);
            if (password_len > 0)
            {
                password[password_len-1] = '\0';
            }
            /* Read the data to be decrypted from a file */
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(toBeDecrypted, sizeof(char), 100, file) != 100)
            {
                fclose(file);
                exit(1);
            }
            toBeDecrypted[99] = '\0';
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
            /* Hash the password */
            if(!CryptHashData(hash, (BYTE *) password, password_len, 0))
            {
                printLine("Error in hashing password");
                exit(1);
            }
            /* Derive a Triple-DES key from the Hashed password */
            if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
            {
                printLine("Error in CryptDeriveKey");
                exit(1);
            }
            /* FIX: Decrypt using Triple-DES */
            if(!CryptDecrypt(key, 0, 1, 0, (BYTE *)toBeDecrypted, &toBeDecryptedLen))
            {
                printLine("Error in decryption");
                exit(1);
            }
            printLine(toBeDecrypted);
            /* Cleanup */
            CryptReleaseContext(cryptoprov,0);
            CryptDestroyHash(hash);
            CryptDestroyKey(key);
            fclose(file);
#endif
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            FILE *file;
            HCRYPTPROV cryptoprov;
            HCRYPTKEY key;
            HCRYPTHASH hash;
            char password[100];
            size_t password_len;
            char toBeDecrypted[100];
            DWORD toBeDecryptedLen = sizeof(toBeDecrypted)-1;
            /* Read the password from the console */
            printLine("Enter the password: ");
            fgets(password, 100, stdin);
            /* The next 3 lines remove the carriage return from the string that is
            * inserted by fgets() */
            password_len = strlen(password);
            if (password_len > 0)
            {
                password[password_len-1] = '\0';
            }
            /* Read the data to be decrypted from a file */
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(toBeDecrypted, sizeof(char), 100, file) != 100)
            {
                fclose(file);
                exit(1);
            }
            toBeDecrypted[99] = '\0';
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
            /* Hash the password */
            if(!CryptHashData(hash, (BYTE *) password, password_len, 0))
            {
                printLine("Error in hashing password");
                exit(1);
            }
            /* Derive a Triple-DES key from the Hashed password */
            if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
            {
                printLine("Error in CryptDeriveKey");
                exit(1);
            }
            /* FIX: Decrypt using Triple-DES */
            if(!CryptDecrypt(key, 0, 1, 0, (BYTE *)toBeDecrypted, &toBeDecryptedLen))
            {
                printLine("Error in decryption");
                exit(1);
            }
            printLine(toBeDecrypted);
            /* Cleanup */
            CryptReleaseContext(cryptoprov,0);
            CryptDestroyHash(hash);
            CryptDestroyKey(key);
            fclose(file);
#endif
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *file;
            /* this name may provide a "hint" to static scanners that we intend for this to be "encrypted" */
            char encrypted_block[BLOCK_SZ+1];
            char decrypted_block[BLOCK_SZ+1];
            char ascii_key[ASCII_KEY_WITH_PADDING_SZ];
            char *replace;
            size_t i, j, key_sz;
            printLine("Input key: ");
            if (fgets(ascii_key, ASCII_KEY_WITH_PADDING_SZ, stdin) == NULL)
            {
                exit(1);
            }
            replace = strchr(ascii_key, '\r');
            if (replace) *replace = '\0';
            replace = strchr(ascii_key, '\n');
            if (replace) *replace = '\0';
            /* we require a key with sufficient entropy (128 bits)
             * (this also assumes the key was randomly generated)
             */
            key_sz = strlen(ascii_key);
            if (key_sz < ASCII_KEY_SZ) exit(1);
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) exit(1);
            if (fread(encrypted_block, sizeof(char), BLOCK_SZ, file) != BLOCK_SZ)
            {
                fclose(file);
                exit(1);
            }
            encrypted_block[BLOCK_SZ] = '\0';
            decrypted_block[BLOCK_SZ] = '\0';
            /* FLAW: "decrypt" the block by XORing with the provided key */
            for (i = 0, j = 0; i < BLOCK_SZ; i++, j++)
            {
                if (j == key_sz) j = 0;
                decrypted_block[i] = encrypted_block[i] ^ ascii_key[j];
            }
            printLine(decrypted_block);
            fclose(file);
        }
    }
}

void CWE327_Use_Broken_Crypto__w32xor_05_good()
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
    CWE327_Use_Broken_Crypto__w32xor_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE327_Use_Broken_Crypto__w32xor_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
