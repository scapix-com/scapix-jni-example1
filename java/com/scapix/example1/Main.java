package com.scapix.example1;

public class Main
{
	static void testClass1()
	{
		Class1 c1 = new Class1();
		var s1 = c1.function1(new String[]{"one", "two", "three"});
		var s2 = Class1.function2(new String[]{"four", "five", "six"});

		System.out.println("testClass1: " + s1 + ", " + s2);
	}

	static void testClass2()
	{
		Class2 c2 = new Class2();
		var s1 = c2.function1(new String[]{"one", "two", "three"});
		var s2 = Class2.function2(new String[]{"four", "five", "six"});

		System.out.println("testClass1: " + s1 + ", " + s2);
	}

	static void testClass3()
	{
		Class3 c3 = new Class3();
		var s1 = c3.function1(new String[]{"one", "two", "three"});
		var s2 = Class3.function2(new String[]{"four", "five", "six"});

		System.out.println("testClass1: " + s1 + ", " + s2);
	}

	public static void main(String[] args)
	{
		System.out.println("Main start");

		testClass1();
		testClass2();
		testClass3();

		System.out.println("Main end");
	}
}
