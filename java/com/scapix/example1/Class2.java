package com.scapix.example1;

public class Class2
{
	private long ptr;

	public native java.lang.String function1(java.lang.String[] strings);
	public static native java.lang.String function2(java.lang.String[] strings);

	@SuppressWarnings({"deprecation","removal"})
	@Override
	protected native void finalize();

	static { System.loadLibrary("example1_cpp"); }
}
