/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_tcp_for_loop_52b.java
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52b.tmpl.java
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_tcp Read count using an outbound tcp connection
 * GoodSource: A hardcoded non-zero, non-min, non-max, even number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 52 Data flow: data passed as an argument from one method to another to another in three different classes in the same package
 *
 * */






public class CWE400_Resource_Exhaustion__connect_tcp_for_loop_52b
{
    public void badSink(int count ) throws Throwable
    {
        (new CWE400_Resource_Exhaustion__connect_tcp_for_loop_52c()).badSink(count );
    }

    /* goodG2B() - use goodsource and badsink */
    public void goodG2BSink(int count ) throws Throwable
    {
        (new CWE400_Resource_Exhaustion__connect_tcp_for_loop_52c()).goodG2BSink(count );
    }

    /* goodB2G() - use badsource and goodsink */
    public void goodB2GSink(int count ) throws Throwable
    {
        (new CWE400_Resource_Exhaustion__connect_tcp_for_loop_52c()).goodB2GSink(count );
    }
}
