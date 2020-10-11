/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53c.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
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
# define PATH_SZ 100
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
# define PATH_SZ PATH_MAX
#endif

#define TCP_PORT 27015

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53c_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53c_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53c_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_connect_socket_printf_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
