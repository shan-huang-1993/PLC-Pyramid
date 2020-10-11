/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c.c
Label Definition File: CWE319_Plaintext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 319 Plaintext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d_bad_sink(wchar_t * password);

void CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c_bad_sink(wchar_t * password)
{
    CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d_goodG2B_sink(wchar_t * password);

/* goodG2B uses the GoodSource with the BadSink */
void CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53c_goodG2B_sink(wchar_t * password)
{
    CWE319_Plaintext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_53d_goodG2B_sink(password);
}

#endif /* OMITGOOD */
