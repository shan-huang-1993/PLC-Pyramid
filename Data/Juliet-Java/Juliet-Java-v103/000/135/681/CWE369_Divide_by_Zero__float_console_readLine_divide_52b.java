/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_console_readLine_divide_52b.java
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-52b.tmpl.java
*/
/*
 * @description
 * CWE: 369 Divide by zero
 * BadSource: console_readLine Read data from the console using readLine
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Dividing by a value that may be zero
 * Flow Variant: 52 Data flow: data passed as an argument from one method to another to another in three different classes in the same package
 *
 * */




public class CWE369_Divide_by_Zero__float_console_readLine_divide_52b
{
    public void badSink(float data ) throws Throwable
    {
        (new CWE369_Divide_by_Zero__float_console_readLine_divide_52c()).badSink(data );
    }

    /* goodG2B() - use goodsource and badsink */
    public void goodG2BSink(float data ) throws Throwable
    {
        (new CWE369_Divide_by_Zero__float_console_readLine_divide_52c()).goodG2BSink(data );
    }

    /* goodB2G() - use badsource and goodsink */
    public void goodB2GSink(float data ) throws Throwable
    {
        (new CWE369_Divide_by_Zero__float_console_readLine_divide_52c()).goodB2GSink(data );
    }
}
