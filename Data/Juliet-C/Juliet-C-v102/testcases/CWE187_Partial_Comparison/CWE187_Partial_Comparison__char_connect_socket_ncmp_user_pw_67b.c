/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Provide a matching password
 * Sinks: ncmp_user_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the user password
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67_struct_type
{
    char * a;
} CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67_struct_type;

#ifndef OMITBAD

void CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67b_bad_sink(CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* By using the strlen() of the input password, you are able to create a partial comparison
     * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
    /* POTENTIAL FLAW: Possibly partially compare the two passwords */
    if (strncmp(PASSWORD, data, strlen(data)) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67b_goodG2B_sink(CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* By using the strlen() of the input password, you are able to create a partial comparison
     * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
    /* POTENTIAL FLAW: Possibly partially compare the two passwords */
    if (strncmp(PASSWORD, data, strlen(data)) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67b_goodB2G_sink(CWE187_Partial_Comparison__char_connect_socket_ncmp_user_pw_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* Ideally, we would want to do a check to see if the passwords are of equal length */
    /* FIX: Compare the two passwords completely and correctly */
    if (strcmp(PASSWORD, data) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITGOOD */