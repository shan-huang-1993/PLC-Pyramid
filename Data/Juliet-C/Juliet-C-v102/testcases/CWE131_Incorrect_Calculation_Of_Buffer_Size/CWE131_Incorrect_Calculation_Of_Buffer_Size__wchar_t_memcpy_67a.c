/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type
{
    wchar_t * a;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67b_bad_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type my_struct);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_bad()
{
    wchar_t * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type my_struct;
    data = NULL;
    /* FLAW: Did not leave space for a null terminator */
    data = (wchar_t *)malloc(10*sizeof(wchar_t));
    my_struct.a = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67b_goodG2B_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_struct_type my_struct;
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    my_struct.a = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67b_goodG2B_sink(my_struct);
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
