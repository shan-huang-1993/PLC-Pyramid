/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_connect_socket_53b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
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
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__int_connect_socket_53c_bad_sink(int data);

void CWE191_Integer_Underflow__int_connect_socket_53b_bad_sink(int data)
{
    CWE191_Integer_Underflow__int_connect_socket_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_connect_socket_53c_goodG2B_sink(int data);

void CWE191_Integer_Underflow__int_connect_socket_53b_goodG2B_sink(int data)
{
    CWE191_Integer_Underflow__int_connect_socket_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_connect_socket_53c_goodB2G_sink(int data);

void CWE191_Integer_Underflow__int_connect_socket_53b_goodB2G_sink(int data)
{
    CWE191_Integer_Underflow__int_connect_socket_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
