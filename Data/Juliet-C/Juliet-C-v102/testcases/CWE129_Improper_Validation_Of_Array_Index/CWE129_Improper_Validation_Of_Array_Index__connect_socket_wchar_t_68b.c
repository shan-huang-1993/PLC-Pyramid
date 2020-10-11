/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Larger than zero but less than 10
 * Sinks: wchar_t
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad_data;
extern int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodG2B_data;
extern int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodB2G_data;

#ifndef OMITBAD

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_bad_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad_data;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodG2B_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodG2B_data;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodB2G_sink()
{
    int data = CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodB2G_data;
    {
        wchar_t data_buf[10] = L"AAAAAAAAA";
        /* FIX: Properly validate the array index */
        if (data >= 0 && data < (10-1))  /* Include the -1 because we don't want to print null */
        {
            printWcharLine(data_buf[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

#endif /* OMITGOOD */
