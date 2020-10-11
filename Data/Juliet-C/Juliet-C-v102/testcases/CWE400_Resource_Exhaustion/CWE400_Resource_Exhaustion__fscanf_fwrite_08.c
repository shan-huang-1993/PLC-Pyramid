/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_08.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fscanf_fwrite_08_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    if(static_returns_t())
    {
        fscanf (stdin, "%d", &count);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(static_returns_t())
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(static_returns_t())
    {
        fscanf (stdin, "%d", &count);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    else
    {
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(static_returns_t())
    {
        fscanf (stdin, "%d", &count);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(static_returns_t())
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B1() - use goodsource and badsink by changing the first static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &count);
    }
    else
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(static_returns_t())
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(static_returns_t())
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &count);
    }
    if(static_returns_t())
    {
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

void CWE400_Resource_Exhaustion__fscanf_fwrite_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE400_Resource_Exhaustion__fscanf_fwrite_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fscanf_fwrite_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
