/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_alloca_loop_68a.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

char * CWE127_Buffer_Underread__char_alloca_loop_68_bad_data;
char * CWE127_Buffer_Underread__char_alloca_loop_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE127_Buffer_Underread__char_alloca_loop_68b_bad_sink();

void CWE127_Buffer_Underread__char_alloca_loop_68_bad()
{
    char * data;
    char * data_buf = (char *)ALLOCA(100*sizeof(char));
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = data_buf - 8;
    CWE127_Buffer_Underread__char_alloca_loop_68_bad_data = data;
    CWE127_Buffer_Underread__char_alloca_loop_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE127_Buffer_Underread__char_alloca_loop_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * data_buf = (char *)ALLOCA(100*sizeof(char));
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = data_buf;
    CWE127_Buffer_Underread__char_alloca_loop_68_goodG2B_data = data;
    CWE127_Buffer_Underread__char_alloca_loop_68b_goodG2B_sink();
}

void CWE127_Buffer_Underread__char_alloca_loop_68_good()
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
    CWE127_Buffer_Underread__char_alloca_loop_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__char_alloca_loop_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
