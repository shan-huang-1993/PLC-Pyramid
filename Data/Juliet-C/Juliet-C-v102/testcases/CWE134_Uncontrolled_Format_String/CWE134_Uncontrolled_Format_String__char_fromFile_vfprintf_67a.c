/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfprintf with a format string
 *    BadSink : vfprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct);

void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_bad()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN("C:\\temp\\file.txt", "r");
            if (pFile != NULL)
            {
                fgets(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct);

static void goodB2G()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN("C:\\temp\\file.txt", "r");
            if (pFile != NULL)
            {
                fgets(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodB2G_sink(my_struct);
}

void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_good()
{
    goodG2B();
    goodB2G();
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
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
