/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE367_TOC_TOU__stat_09.c
Label Definition File: CWE367_TOC_TOU.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 367 Time-of-Check Time-Of-Use Race Condition
 * Sinks: stat
 *    GoodSink: Open the file without checking the status information
 *    BadSink : Get status information on file using stat(), open, write to, and close the file
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define STAT _stat
# define OPEN _open
# define WRITE _write
# define O_CREAT _O_CREAT
# define O_EXCL _O_EXCL
# define O_RDWR _O_RDWR
# define S_IREAD _S_IREAD
# define S_IWRITE _S_IWRITE
# define CLOSE _close
# define FSTAT _fstat
#else
# define STAT stat
# define OPEN open
# define WRITE write
# define CLOSE close
# define FSTAT fstat
#endif

#ifndef OMITBAD

void CWE367_TOC_TOU__stat_09_bad()
{
    if(global_const_t)
    {
        {
            char filename[100] = "";
            struct STAT statbuf;
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            if (STAT(filename, &statbuf) == -1) exit(1);
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            /* FLAW: Open and write to the file without a call to fstat() */
            if (fd == -1) exit(1);
            if (WRITE(fd, "Bad Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char filename[100] = "";
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            /* FIX: Open the file without checking the status information */
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            if (fd == -1) exit(1);
            if (WRITE(fd, "Good Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char filename[100] = "";
            struct STAT statbuf;
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            if (STAT(filename, &statbuf) == -1) exit(1);
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            /* FLAW: Open and write to the file without a call to fstat() */
            if (fd == -1) exit(1);
            if (WRITE(fd, "Bad Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
    else
    {
        {
            char filename[100] = "";
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            /* FIX: Open the file without checking the status information */
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            if (fd == -1) exit(1);
            if (WRITE(fd, "Good Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        {
            char filename[100] = "";
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            /* FIX: Open the file without checking the status information */
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            if (fd == -1) exit(1);
            if (WRITE(fd, "Good Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char filename[100] = "";
            struct STAT statbuf;
            int fd = -1;
            fgets(filename, 100, stdin);
            filename[strlen(filename)-1] = '\0'; /* remove newline */
            if (STAT(filename, &statbuf) == -1) exit(1);
            fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);
            /* FLAW: Open and write to the file without a call to fstat() */
            if (fd == -1) exit(1);
            if (WRITE(fd, "Bad Sink...", 25) == -1) exit(1);
            if (fd != -1) CLOSE(fd);
        }
    }
}

void CWE367_TOC_TOU__stat_09_good()
{
    good1();
    good2();
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
    CWE367_TOC_TOU__stat_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE367_TOC_TOU__stat_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
