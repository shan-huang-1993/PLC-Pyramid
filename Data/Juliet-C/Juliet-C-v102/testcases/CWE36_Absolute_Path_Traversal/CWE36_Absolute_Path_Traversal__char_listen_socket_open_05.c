/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_listen_socket_open_05.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Full path and file name
 * Sink: open
 *    BadSink :
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ FILENAME_MAX
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define PATH_SZ PATH_MAX
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__char_listen_socket_open_05_bad()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_t)
    {
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            char *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = strlen(data);
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listen_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(TCP_PORT);
                if (bind(listen_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                if (listen(listen_socket, LISTEN_BACKLOG) == SOCKET_ERROR) break;
                accept_socket = accept(listen_socket, NULL, NULL);
                if (accept_socket == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed */
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(FILENAME_MAX-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = '\0';
                /* Eliminate CRLF */
                replace = strchr(data, '\r');
                if (replace) *replace = '\0';
                replace = strchr(data, '\n');
                if (replace) *replace = '\0';
            }
            while (0);
            if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
            if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    {
        int fd;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            CLOSE(fd);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            char *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = strlen(data);
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listen_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(TCP_PORT);
                if (bind(listen_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                if (listen(listen_socket, LISTEN_BACKLOG) == SOCKET_ERROR) break;
                accept_socket = accept(listen_socket, NULL, NULL);
                if (accept_socket == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed */
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(FILENAME_MAX-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = '\0';
                /* Eliminate CRLF */
                replace = strchr(data, '\r');
                if (replace) *replace = '\0';
                replace = strchr(data, '\n');
                if (replace) *replace = '\0';
            }
            while (0);
            if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
            if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    else
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    {
        int fd;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            CLOSE(fd);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_t)
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            char *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = strlen(data);
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listen_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(TCP_PORT);
                if (bind(listen_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                if (listen(listen_socket, LISTEN_BACKLOG) == SOCKET_ERROR) break;
                accept_socket = accept(listen_socket, NULL, NULL);
                if (accept_socket == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed */
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(FILENAME_MAX-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = '\0';
                /* Eliminate CRLF */
                replace = strchr(data, '\r');
                if (replace) *replace = '\0';
                replace = strchr(data, '\n');
                if (replace) *replace = '\0';
            }
            while (0);
            if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
            if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    {
        int fd;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            CLOSE(fd);
        }
    }
}

void CWE36_Absolute_Path_Traversal__char_listen_socket_open_05_good()
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
    CWE36_Absolute_Path_Traversal__char_listen_socket_open_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_listen_socket_open_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
