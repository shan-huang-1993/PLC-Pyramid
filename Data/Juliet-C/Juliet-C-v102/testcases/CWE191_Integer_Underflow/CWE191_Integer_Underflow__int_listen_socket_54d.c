/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_listen_socket_54d.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__int_listen_socket_54e_bad_sink(int data);

void CWE191_Integer_Underflow__int_listen_socket_54d_bad_sink(int data)
{
    CWE191_Integer_Underflow__int_listen_socket_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_listen_socket_54e_goodG2B_sink(int data);

void CWE191_Integer_Underflow__int_listen_socket_54d_goodG2B_sink(int data)
{
    CWE191_Integer_Underflow__int_listen_socket_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_listen_socket_54e_goodB2G_sink(int data);

void CWE191_Integer_Underflow__int_listen_socket_54d_goodB2G_sink(int data)
{
    CWE191_Integer_Underflow__int_listen_socket_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
