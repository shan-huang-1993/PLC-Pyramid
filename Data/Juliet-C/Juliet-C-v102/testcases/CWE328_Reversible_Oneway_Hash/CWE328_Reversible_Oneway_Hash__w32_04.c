/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE328_Reversible_Oneway_Hash__w32_04.c
Label Definition File: CWE328_Reversible_Oneway_Hash__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 328 Reversible Oneway Hash
 * Sinks:
 *    GoodSink: Use SHA1 as a hashing algorithm
 *    BadSink : Use Adler32 CRC to hash the password
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <windows.h>
# include <wincrypt.h>
#endif

#ifdef _WIN32
#define PASSWORD_SZ 32
#define PASSWORD_INPUT_SZ (PASSWORD_SZ + 10) /* maintenance note: ensure this is bug enough for any newline nonsense from fgets, and it must be > 2*SHA1SUM_SIZE */
#define ADLER_A_INIT 1
#define ADLER_B_INIT 0
#define ADLER_MOD 65521
#define SHA1SUM_SIZE 20
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE328_Reversible_Oneway_Hash__w32_04_bad()
{
    if(static_const_t)
    {
        {
#ifdef _WIN32
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            ULONG a, b, password_crc, compare_crc;
            char *replace;
            size_t i, len;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            /* INCIDENTAL: CWE 256 - Storage of Plaintext Password
             */
            if (fscanf(password_file, "%x", &password_crc) != 1)
            {
                fclose(password_file);
                exit(1);
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            /* FLAW: Using Adler32 CRC to "hash" the password, which is reversible (or
             * at least trivial to conduct "pre-image attacks")
             */
            len = strlen(password);
            a = ADLER_A_INIT;
            b = ADLER_B_INIT;
            for (i = 0; i < len; i++)
            {
                a = (a + password[i]) % ADLER_MOD;
                b = (b + a) % ADLER_MOD;
            }
            compare_crc = (b << 16) | a;
            if (password_crc == compare_crc)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
            HCRYPTPROV Prov;
            HCRYPTHASH Hash;
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            UCHAR saved_hash[SHA1SUM_SIZE], calc_hash[SHA1SUM_SIZE];
            DWORD hash_size;
            char *replace;
            size_t i;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            for (i = 0; i < SHA1SUM_SIZE; i++)
            {
                ULONG val;
                if (fscanf(password_file, "%02x", &val) != 1)
                {
                    fclose(password_file);
                    exit(1);
                }
                if (val > 0xff)   /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
                {
                    fclose(password_file);
                    exit(1);
                }
                saved_hash[i] = (UCHAR)val;
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            if (!CryptAcquireContextW(&Prov, 0, 0, PROV_RSA_FULL, 0)) exit(1);
            if (!CryptCreateHash(Prov, CALG_SHA1, 0, 0, &Hash))
            {
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
             * the password hash was not securely transmitted (via one form or another),
             * that may raise flags
             */
            /* FIX: compare passwords using non-reversible hash (SHA1) */
            if (!CryptHashData(Hash, (BYTE*)password, strlen(password), 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            hash_size = SHA1SUM_SIZE;
            if (!CryptGetHashParam(Hash, HP_HASHVAL, (BYTE*)calc_hash, &hash_size, 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            if (memcmp(saved_hash, calc_hash, SHA1SUM_SIZE * sizeof(UCHAR)) == 0)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
            CryptDestroyHash(Hash);
            CryptReleaseContext(Prov, 0);
#endif /* _WIN32 */
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
#ifdef _WIN32
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            ULONG a, b, password_crc, compare_crc;
            char *replace;
            size_t i, len;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            /* INCIDENTAL: CWE 256 - Storage of Plaintext Password
             */
            if (fscanf(password_file, "%x", &password_crc) != 1)
            {
                fclose(password_file);
                exit(1);
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            /* FLAW: Using Adler32 CRC to "hash" the password, which is reversible (or
             * at least trivial to conduct "pre-image attacks")
             */
            len = strlen(password);
            a = ADLER_A_INIT;
            b = ADLER_B_INIT;
            for (i = 0; i < len; i++)
            {
                a = (a + password[i]) % ADLER_MOD;
                b = (b + a) % ADLER_MOD;
            }
            compare_crc = (b << 16) | a;
            if (password_crc == compare_crc)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
            HCRYPTPROV Prov;
            HCRYPTHASH Hash;
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            UCHAR saved_hash[SHA1SUM_SIZE], calc_hash[SHA1SUM_SIZE];
            DWORD hash_size;
            char *replace;
            size_t i;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            for (i = 0; i < SHA1SUM_SIZE; i++)
            {
                ULONG val;
                if (fscanf(password_file, "%02x", &val) != 1)
                {
                    fclose(password_file);
                    exit(1);
                }
                if (val > 0xff)   /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
                {
                    fclose(password_file);
                    exit(1);
                }
                saved_hash[i] = (UCHAR)val;
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            if (!CryptAcquireContextW(&Prov, 0, 0, PROV_RSA_FULL, 0)) exit(1);
            if (!CryptCreateHash(Prov, CALG_SHA1, 0, 0, &Hash))
            {
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
             * the password hash was not securely transmitted (via one form or another),
             * that may raise flags
             */
            /* FIX: compare passwords using non-reversible hash (SHA1) */
            if (!CryptHashData(Hash, (BYTE*)password, strlen(password), 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            hash_size = SHA1SUM_SIZE;
            if (!CryptGetHashParam(Hash, HP_HASHVAL, (BYTE*)calc_hash, &hash_size, 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            if (memcmp(saved_hash, calc_hash, SHA1SUM_SIZE * sizeof(UCHAR)) == 0)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
            CryptDestroyHash(Hash);
            CryptReleaseContext(Prov, 0);
#endif /* _WIN32 */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
            HCRYPTPROV Prov;
            HCRYPTHASH Hash;
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            UCHAR saved_hash[SHA1SUM_SIZE], calc_hash[SHA1SUM_SIZE];
            DWORD hash_size;
            char *replace;
            size_t i;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            for (i = 0; i < SHA1SUM_SIZE; i++)
            {
                ULONG val;
                if (fscanf(password_file, "%02x", &val) != 1)
                {
                    fclose(password_file);
                    exit(1);
                }
                if (val > 0xff)   /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
                {
                    fclose(password_file);
                    exit(1);
                }
                saved_hash[i] = (UCHAR)val;
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            if (!CryptAcquireContextW(&Prov, 0, 0, PROV_RSA_FULL, 0)) exit(1);
            if (!CryptCreateHash(Prov, CALG_SHA1, 0, 0, &Hash))
            {
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
             * the password hash was not securely transmitted (via one form or another),
             * that may raise flags
             */
            /* FIX: compare passwords using non-reversible hash (SHA1) */
            if (!CryptHashData(Hash, (BYTE*)password, strlen(password), 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            hash_size = SHA1SUM_SIZE;
            if (!CryptGetHashParam(Hash, HP_HASHVAL, (BYTE*)calc_hash, &hash_size, 0))
            {
                CryptDestroyHash(Hash);
                CryptReleaseContext(Prov, 0);
                exit(1);
            }
            if (memcmp(saved_hash, calc_hash, SHA1SUM_SIZE * sizeof(UCHAR)) == 0)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
            CryptDestroyHash(Hash);
            CryptReleaseContext(Prov, 0);
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            FILE *password_file = NULL;
            char password[PASSWORD_INPUT_SZ];
            ULONG a, b, password_crc, compare_crc;
            char *replace;
            size_t i, len;
            password_file = fopen("password.txt", "r");
            if (password_file == NULL) exit(1);
            /* INCIDENTAL: CWE 256 - Storage of Plaintext Password
             */
            if (fscanf(password_file, "%x", &password_crc) != 1)
            {
                fclose(password_file);
                exit(1);
            }
            fclose(password_file);
            if (fgets(password, PASSWORD_INPUT_SZ, stdin) == NULL) exit(1);
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
            /* FLAW: Using Adler32 CRC to "hash" the password, which is reversible (or
             * at least trivial to conduct "pre-image attacks")
             */
            len = strlen(password);
            a = ADLER_A_INIT;
            b = ADLER_B_INIT;
            for (i = 0; i < len; i++)
            {
                a = (a + password[i]) % ADLER_MOD;
                b = (b + a) % ADLER_MOD;
            }
            compare_crc = (b << 16) | a;
            if (password_crc == compare_crc)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
            }
#endif /* _WIN32 */
        }
    }
}

void CWE328_Reversible_Oneway_Hash__w32_04_good()
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
    CWE328_Reversible_Oneway_Hash__w32_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE328_Reversible_Oneway_Hash__w32_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
