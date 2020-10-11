/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_64b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fgets_fwrite_64b_bad_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_64b_goodG2B_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
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

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_64b_goodB2G_sink(void * void_count_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * count_ptr = (int *)void_count_ptr;
    /* dereference count_ptr into count */
    int count = (*count_ptr);
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

#endif /* OMITGOOD */
