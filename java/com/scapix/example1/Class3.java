package com.scapix.example1;

public class Class3
{
	public native java.lang.String function1(java.lang.String[] strings);
	public static native java.lang.String function2(java.lang.String[] strings);

	static { System.loadLibrary("example1_cpp"); }
}
