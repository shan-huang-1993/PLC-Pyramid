/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_listen_socket_str_54d.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strstr() to do password match, which is a partial comparison
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

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

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__char_listen_socket_str_54e_bad_sink(char * data);

void CWE187_Partial_Comparison__char_listen_socket_str_54d_bad_sink(char * data)
{
    CWE187_Partial_Comparison__char_listen_socket_str_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_listen_socket_str_54e_goodG2B_sink(char * data);

void CWE187_Partial_Comparison__char_listen_socket_str_54d_goodG2B_sink(char * data)
{
    CWE187_Partial_Comparison__char_listen_socket_str_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_listen_socket_str_54e_goodB2G_sink(char * data);

void CWE187_Partial_Comparison__char_listen_socket_str_54d_goodB2G_sink(char * data)
{
    CWE187_Partial_Comparison__char_listen_socket_str_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
