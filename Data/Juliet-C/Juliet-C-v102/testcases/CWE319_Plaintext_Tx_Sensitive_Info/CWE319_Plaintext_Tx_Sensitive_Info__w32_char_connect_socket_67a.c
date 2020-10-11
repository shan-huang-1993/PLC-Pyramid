/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67a.c
Label Definition File: CWE319_Plaintext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 319 Plaintext Transmission of Sensitive Information
 * BadSource: connect_socket Read the password using a connect socket (client side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

typedef struct _CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type
{
    char * a;
} CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67b_bad_sink(CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type my_struct);

void CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_bad()
{
    char * password;
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type my_struct;
    char password_buf[100] = "";
    password = password_buf;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        char *replace;
        SOCKET connect_socket = INVALID_SOCKET;
        size_t password_len = strlen(password);
        do
        {
#ifdef _WIN32
            if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
            wsa_data_init = 1;
#endif
            connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connect_socket == INVALID_SOCKET) break;
            memset(&s_in, 0, sizeof(s_in));
            s_in.sin_family = AF_INET;
            s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
            s_in.sin_port = htons(TCP_PORT);
            if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            /* FLAW: Reading plaintext data from the network */
            recv_rv = recv(connect_socket, (char*)password+password_len, (int)(100-password_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            password[recv_rv] = '\0';
            /* Eliminate CRLF */
            replace = strchr(password, '\r');
            if (replace) *replace = '\0';
            replace = strchr(password, '\n');
            if (replace) *replace = '\0';
        }
        while (0);
        if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    my_struct.a = password;
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67b_goodG2B_sink(CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type my_struct);

static void goodG2B()
{
    char * password;
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_struct_type my_struct;
    char password_buf[100] = "";
    password = password_buf;
    /* FIX: Use a hardcoded password (it was not sent over the network)
     * INCIDENTAL FLAW: CWE-259 Hard Coded Password */
    strcpy(password, "Password1234!");
    my_struct.a = password;
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67b_goodG2B_sink(my_struct);
}

void CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_good()
{
    goodG2B();
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
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE319_Plaintext_Tx_Sensitive_Info__w32_char_connect_socket_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
