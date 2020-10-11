/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_18.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: wrong_ptr_print
 *    GoodSink: Subtract pointers correctly and print data
 *    BadSink : Subtract pointers to two different strings
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data;
        char string1[] = SRC_STR;
        char string2[] = SRC_STR;
        char * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = strchr(string1, '/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
        indexOfSlashInString1 = (size_t)(slashInString1 - string1);
        /* print what comes after the slash */
        data = &(string1[indexOfSlashInString1+1]);
        printLine(data);
        printLine(string2); /* suppress warning about unused string2 */
    }
sink:
    {
        char * data;
        char string1[] = SRC_STR;
        char string2[] = SRC_STR;
        char * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = strchr(string1, '/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
        indexOfSlashInString1 = (size_t)(slashInString1 - string2);
        /* print what comes after the slash */
        data = &(string1[indexOfSlashInString1+1]);
        printLine(data);
        printLine(string2); /* suppress warning about unused string2 */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data;
        char string1[] = SRC_STR;
        char string2[] = SRC_STR;
        char * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = strchr(string1, '/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
        indexOfSlashInString1 = (size_t)(slashInString1 - string2);
        /* print what comes after the slash */
        data = &(string1[indexOfSlashInString1+1]);
        printLine(data);
        printLine(string2); /* suppress warning about unused string2 */
    }
sink:
    {
        char * data;
        char string1[] = SRC_STR;
        char string2[] = SRC_STR;
        char * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = strchr(string1, '/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
        indexOfSlashInString1 = (size_t)(slashInString1 - string1);
        /* print what comes after the slash */
        data = &(string1[indexOfSlashInString1+1]);
        printLine(data);
        printLine(string2); /* suppress warning about unused string2 */
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_18_good()
{
    good1();
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
