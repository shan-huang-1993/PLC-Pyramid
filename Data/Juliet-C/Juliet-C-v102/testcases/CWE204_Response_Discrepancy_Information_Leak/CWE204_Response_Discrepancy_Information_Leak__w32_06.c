/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE204_Response_Discrepancy_Information_Leak__w32_06.c
Label Definition File: CWE204_Response_Discrepancy_Information_Leak__w32.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 204 Response Discrepancy Information Leak
 * Sinks:
 *    GoodSink: Send a failed message, but don't provide user or password info
 *    BadSink : Responses leak information (invalid user, invalid password, etc)
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# pragma comment(lib, "ws2_32")
#endif

#ifdef _WIN32
#define CLOSESOCKET closesocket
#define UNLINK _unlink
#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5
#define USERNAME_SZ 15
#define PASSWORD_SZ 15
#define THE_USER "abcdefghijklmno"
#define THE_PASSWORD "!HF82p(fnbanw46"
#endif

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE204_Response_Discrepancy_Information_Leak__w32_06_bad()
{
    if(static_const_five==5)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FLAW: Responses leak information (invalid user, invalid password, etc) */
                if (strcmp(username, THE_USER) != 0)
                {
                    char msg[] = "Invalid username";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    if (strcmp(password, THE_PASSWORD) != 0)
                    {
                        char msg[] = "Invalid password";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                    else
                    {
                        char msg[] = "Welcome";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FIX: Send a "auth failed" message, but don't provide user vs. password info */
                if (strcmp(username, THE_USER) != 0 ||
                        strcmp(password, THE_PASSWORD) != 0)
                {
                    char msg[] = "Invalid attempt";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    char msg[] = "Welcome";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_five!=5) instead of if(static_const_five==5) */
static void good1()
{
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FLAW: Responses leak information (invalid user, invalid password, etc) */
                if (strcmp(username, THE_USER) != 0)
                {
                    char msg[] = "Invalid username";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    if (strcmp(password, THE_PASSWORD) != 0)
                    {
                        char msg[] = "Invalid password";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                    else
                    {
                        char msg[] = "Welcome";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FIX: Send a "auth failed" message, but don't provide user vs. password info */
                if (strcmp(username, THE_USER) != 0 ||
                        strcmp(password, THE_PASSWORD) != 0)
                {
                    char msg[] = "Invalid attempt";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    char msg[] = "Welcome";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_five==5)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FIX: Send a "auth failed" message, but don't provide user vs. password info */
                if (strcmp(username, THE_USER) != 0 ||
                        strcmp(password, THE_PASSWORD) != 0)
                {
                    char msg[] = "Invalid attempt";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    char msg[] = "Welcome";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            char password[PASSWORD_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                if (sizeof(password)-sizeof(char) != recv(client, password, sizeof(password)-sizeof(char), 0)) break;
                password[PASSWORD_SZ] = '\0';
                /* INCIDENTAL: CWE259 and related -- hard-coded username and password */
                /* FLAW: Responses leak information (invalid user, invalid password, etc) */
                if (strcmp(username, THE_USER) != 0)
                {
                    char msg[] = "Invalid username";
                    if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                }
                else
                {
                    if (strcmp(password, THE_PASSWORD) != 0)
                    {
                        char msg[] = "Invalid password";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                    else
                    {
                        char msg[] = "Welcome";
                        if (sizeof(msg)-sizeof(char) != send(client, msg, sizeof(msg)-sizeof(char), 0)) break;
                    }
                }
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

void CWE204_Response_Discrepancy_Information_Leak__w32_06_good()
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
    CWE204_Response_Discrepancy_Information_Leak__w32_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE204_Response_Discrepancy_Information_Leak__w32_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
