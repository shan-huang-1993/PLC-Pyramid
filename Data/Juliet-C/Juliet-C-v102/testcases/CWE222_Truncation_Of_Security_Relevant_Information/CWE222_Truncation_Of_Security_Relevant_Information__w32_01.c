/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE222_Truncation_Of_Security_Relevant_Information__w32_01.c
Label Definition File: CWE222_Truncation_Of_Security_Relevant_Information__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 222 Truncation of Security Relevant Information
 * Sinks:
 *    GoodSink: Log the complete username
 *    BadSink : Username is truncated before being logged
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# pragma comment(lib, "ws2_32")
#endif

#ifdef _WIN32
# define CLOSESOCKET closesocket
# define UNLINK _unlink
#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5
#define USERNAME_SZ 15
#define TRUNCATED_USERNAME_SZ 4 /* maintenance note: ensure this is < USERNAME_SZ */
#endif

#ifndef OMITBAD

void CWE222_Truncation_Of_Security_Relevant_Information__w32_01_bad()
{
    {
#ifdef _WIN32
        WSADATA wsadata;
        BOOL wsa_init = FALSE;
        SOCKET listener = INVALID_SOCKET;
        SOCKET client = INVALID_SOCKET;
        struct sockaddr_in s_in;
        char username[USERNAME_SZ+1];
        char truncated_username[TRUNCATED_USERNAME_SZ+1];
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
            if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
            username[USERNAME_SZ] = '\0';
            /* INCIDENTAL CWE 188 - reliance on data memory layout
            * recv and friends return "number of bytes" received
            * fwrite wants "the size of".  ANSI/ISO allows the size of chars
            * to be anything (32 bits, 9 bits, etc.) so technically you
            * have to do conversion between these values
            */
            /* FLAW: username is truncated before being logged */
            memcpy(truncated_username, username, sizeof(truncated_username));
            truncated_username[TRUNCATED_USERNAME_SZ] = '\0';
            fprintf(stderr, "User %s logged in\n", truncated_username);
        }
        while (0);
        if (client != INVALID_SOCKET) CLOSESOCKET(client);
        if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
        if (wsa_init) WSACleanup();
#endif /* _WIN32 */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
#ifdef _WIN32
        WSADATA wsadata;
        BOOL wsa_init = FALSE;
        SOCKET listener = INVALID_SOCKET;
        SOCKET client = INVALID_SOCKET;
        struct sockaddr_in s_in;
        char username[USERNAME_SZ+1];
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
            if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
            username[USERNAME_SZ] = '\0';
            /* INCIDENTAL CWE 188 - reliance on data memory layout
            * recv and friends return "number of bytes" received
            * fwrite wants "the size of".  ANSI/ISO allows the size of chars
            * to be anything (32 bits, 9 bits, etc.) so technically you
            * have to do conversion between these values
            */
            /* FIX: log the complete username */
            fprintf(stderr, "User %s logged in\n", username);
        }
        while (0);
        if (client != INVALID_SOCKET) CLOSESOCKET(client);
        if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
        if (wsa_init) WSACleanup();
#endif /* _WIN32 */
    }
}

void CWE222_Truncation_Of_Security_Relevant_Information__w32_01_good()
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
    CWE222_Truncation_Of_Security_Relevant_Information__w32_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE222_Truncation_Of_Security_Relevant_Information__w32_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
