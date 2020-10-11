/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_snprintf_05.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snwprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snwprintf with data as the third argument
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ 100
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
# define SNPRINTF _snwprintf
#else /* NOT _WIN32 */
# define SNPRINTF snwprintf
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_snprintf_05_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
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
            wchar_t *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = wcslen(data);
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
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = L'\0';
                /* Eliminate CRLF */
                replace = wcschr(data, L'\r');
                if (replace) *replace = L'\0';
                replace = wcschr(data, L'\n');
                if (replace) *replace = L'\0';
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
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(static_t)
    {
        {
            wchar_t dest[100] = L"";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dest[100] = L"";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, L"%s", data);
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_t to static_f */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
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
            wchar_t *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = wcslen(data);
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
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = L'\0';
                /* Eliminate CRLF */
                replace = wcschr(data, L'\r');
                if (replace) *replace = L'\0';
                replace = wcschr(data, L'\n');
                if (replace) *replace = L'\0';
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
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dest[100] = L"";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printWLine(dest);
        }
    }
    else
    {
        {
            wchar_t dest[100] = L"";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, L"%s", data);
            printWLine(dest);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
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
            wchar_t *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = wcslen(data);
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
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = L'\0';
                /* Eliminate CRLF */
                replace = wcschr(data, L'\r');
                if (replace) *replace = L'\0';
                replace = wcschr(data, L'\n');
                if (replace) *replace = L'\0';
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
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(static_t)
    {
        {
            wchar_t dest[100] = L"";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, L"%s", data);
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dest[100] = L"";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printWLine(dest);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_t to static_f */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
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
            wchar_t *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = wcslen(data);
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
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = L'\0';
                /* Eliminate CRLF */
                replace = wcschr(data, L'\r');
                if (replace) *replace = L'\0';
                replace = wcschr(data, L'\n');
                if (replace) *replace = L'\0';
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
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(static_t)
    {
        {
            wchar_t dest[100] = L"";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dest[100] = L"";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, L"%s", data);
            printWLine(dest);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_t)
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
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
            wchar_t *replace;
            SOCKET listen_socket = INVALID_SOCKET;
            SOCKET accept_socket = INVALID_SOCKET;
            size_t data_len = wcslen(data);
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
                recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
                /* Append null terminator */
                data[recv_rv] = L'\0';
                /* Eliminate CRLF */
                replace = wcschr(data, L'\r');
                if (replace) *replace = L'\0';
                replace = wcschr(data, L'\n');
                if (replace) *replace = L'\0';
            }
            while (0);
            if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
            if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    if(static_t)
    {
        {
            wchar_t dest[100] = L"";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dest[100] = L"";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, L"%s", data);
            printWLine(dest);
        }
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_snprintf_05_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_snprintf_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_snprintf_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
