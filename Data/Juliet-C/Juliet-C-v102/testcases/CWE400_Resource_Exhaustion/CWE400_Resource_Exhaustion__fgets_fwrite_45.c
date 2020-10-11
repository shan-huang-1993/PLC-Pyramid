/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_45.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#define SENTENCE "This is the sentence we are printing to the file. "

static int CWE400_Resource_Exhaustion__fgets_fwrite_45_bad_data;
static int CWE400_Resource_Exhaustion__fgets_fwrite_45_goodG2B_data;
static int CWE400_Resource_Exhaustion__fgets_fwrite_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    int count = CWE400_Resource_Exhaustion__fgets_fwrite_45_bad_data;
    {
        size_t i = 0;
        FILE *file = NULL;
        const char *filename = "output_bad.txt";
        file = fopen(filename, "w+");
        if (file == NULL) exit(1);
        /* FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), file)) exit(1);
        }
        if (file)
        {
            fclose(file);
        }
    }
}

void CWE400_Resource_Exhaustion__fgets_fwrite_45_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    CWE400_Resource_Exhaustion__fgets_fwrite_45_bad_data = count;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    int count = CWE400_Resource_Exhaustion__fgets_fwrite_45_goodG2B_data;
    {
        size_t i = 0;
        FILE *file = NULL;
        const char *filename = "output_bad.txt";
        file = fopen(filename, "w+");
        if (file == NULL) exit(1);
        /* FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), file)) exit(1);
        }
        if (file)
        {
            fclose(file);
        }
    }
}

static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    CWE400_Resource_Exhaustion__fgets_fwrite_45_goodG2B_data = count;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    int count = CWE400_Resource_Exhaustion__fgets_fwrite_45_goodB2G_data;
    {
        size_t i = 0;
        FILE *file = NULL;
        const char *filename = "output_good.txt";
        /* FIX: Validate count before using it as the for loop variant to write to a file */
        if (count > 0 && count <= 20)
        {
            file = fopen(filename, "w+");
            if (file == NULL) exit(1);
            for (i = 0; i < (size_t)count; i++)
            {
                if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), file)) exit(1);
            }
            if (file)
            {
                fclose(file);
            }
        }
    }
}

static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    CWE400_Resource_Exhaustion__fgets_fwrite_45_goodB2G_data = count;
    goodB2G_sink();
}

void CWE400_Resource_Exhaustion__fgets_fwrite_45_good()
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
    CWE400_Resource_Exhaustion__fgets_fwrite_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_fwrite_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
