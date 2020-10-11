/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32_04.c
Label Definition File: CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 247 Reliance on DNS Lookups in a Security Decision
 * Sinks:
 *    GoodSink: Log host name without using it in a security decision
 *    BadSink : Use the reverse DNS of the client to determine whether to allow the connection
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# pragma comment(lib, "ws2_32")
#endif

#ifdef _WIN32
# define CLOSESOCKET closesocket
#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5
#define SECRET_HOSTNAME "www.domain.nonexistanttld"
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32_04_bad()
{
    if(static_const_t)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* INCIDENTAL: Some CWE about hardcoded information */
                /* FLAW: Using the reverse DNS of the client to determine whether to allow the connection */
                if (strcmp(h_client->h_name, SECRET_HOSTNAME) == 0)
                {
                    printLine("Access granted.");
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
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
            FILE * file;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* FIX: Copy the host name to a log - do not attempt to use the host name in a security decision */
                file = fopen("log.txt", "a+");
                fprintf(file, "Host name: %s\n", h_client->h_name);
                fclose(file);
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

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* INCIDENTAL: Some CWE about hardcoded information */
                /* FLAW: Using the reverse DNS of the client to determine whether to allow the connection */
                if (strcmp(h_client->h_name, SECRET_HOSTNAME) == 0)
                {
                    printLine("Access granted.");
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
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
            FILE * file;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* FIX: Copy the host name to a log - do not attempt to use the host name in a security decision */
                file = fopen("log.txt", "a+");
                fprintf(file, "Host name: %s\n", h_client->h_name);
                fclose(file);
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
    if(static_const_t)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
            FILE * file;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* FIX: Copy the host name to a log - do not attempt to use the host name in a security decision */
                file = fopen("log.txt", "a+");
                fprintf(file, "Host name: %s\n", h_client->h_name);
                fclose(file);
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
            struct sockaddr_in s_in_client;
            int s_in_client_len;
            struct hostent *h_client;
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
                s_in_client_len = sizeof(s_in_client);
                client = accept(listener, (struct sockaddr*)&s_in_client, &s_in_client_len);
                if (client == INVALID_SOCKET) break;
                if (s_in_client.sin_family != AF_INET) break;
                h_client = gethostbyaddr((char*)&s_in_client.sin_addr, sizeof(s_in_client.sin_addr), AF_INET);
                if (h_client == NULL) break;
                if (h_client->h_name == NULL) break;
                printLine(h_client->h_name);
                /* INCIDENTAL: Some CWE about hardcoded information */
                /* FLAW: Using the reverse DNS of the client to determine whether to allow the connection */
                if (strcmp(h_client->h_name, SECRET_HOSTNAME) == 0)
                {
                    printLine("Access granted.");
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

void CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32_04_good()
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
    CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE247_Reliance_On_DNS_Lookups_In_A_Security_Decision__w32_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
