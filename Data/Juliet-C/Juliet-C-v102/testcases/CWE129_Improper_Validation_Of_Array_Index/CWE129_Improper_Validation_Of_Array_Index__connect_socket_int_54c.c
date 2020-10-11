/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54c.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
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
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_bad_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54c_bad_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_goodG2B_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54c_goodG2B_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_goodB2G_sink(int data);

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54c_goodB2G_sink(int data)
{
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_int_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
