/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68b.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
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

extern int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68_bad_data;
extern int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68b_bad_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68_bad_data;
    {
        size_t i;
        int *b;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             so that the for loop doing the initialization causes a buffer overflow */
        b = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* Potentially writes beyond the boundary of b */
        }
        printIntLine(b[0]);
        free(b);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68b_goodG2B_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_connect_socket_68_goodG2B_data;
    {
        size_t i;
        int *b;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             so that the for loop doing the initialization causes a buffer overflow */
        b = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* Potentially writes beyond the boundary of b */
        }
        printIntLine(b[0]);
        free(b);
    }
}

#endif /* OMITGOOD */
