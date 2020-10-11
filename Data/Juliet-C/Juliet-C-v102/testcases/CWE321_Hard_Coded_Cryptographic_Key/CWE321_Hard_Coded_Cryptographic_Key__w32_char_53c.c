/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_53c.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sink:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTOKEY "Hardcoded"

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_53d_bad_sink(char * cryptokey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_53c_bad_sink(char * cryptokey)
{
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_53d_bad_sink(cryptokey);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_53d_goodG2B_sink(char * cryptokey);

/* goodG2B uses the GoodSource with the BadSink */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_53c_goodG2B_sink(char * cryptokey)
{
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_53d_goodG2B_sink(cryptokey);
}

#endif /* OMITGOOD */
