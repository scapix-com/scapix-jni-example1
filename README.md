# Example1 for [Scapix JNI](https://www.scapix.com/jni/)

[Scapix JNI](https://www.scapix.com/jni/) is a modern C++20 library for Java Native Interface ([JNI](https://docs.oracle.com/en/java/javase/25/docs/specs/jni/)).
It provides type-safe APIs and automatic resource management, with zero runtime overhead compared to manually written JNI code.

### Implement Java native methods in C++

- [class1](https://github.com/scapix-com/scapix-jni-example1/blob/master/cpp/source/example1/class1.h) - using C++ free functions.
- [class2](https://github.com/scapix-com/scapix-jni-example1/blob/master/cpp/source/example1/class2.h) - using C++ non-static member functions, with "ptr" field in Java objects.
- [class3](https://github.com/scapix-com/scapix-jni-example1/blob/master/cpp/source/example1/class3.h) - using C++ non-static member functions, with `std::unordered_map` of Java refs to C++ objects.

```java {title="Java"}
package com.scapix.example1;

public class Class1
{
	public native java.lang.String function1(java.lang.String[] strings);
	public static native java.lang.String function2(java.lang.String[] strings);

	static { System.loadLibrary("example1"); }
}
```

```cpp {title="C++"}
#include <scapix/jni/native_method.h>
#include <scapix/java_api/java/lang/String.h>

namespace example1 {

namespace jni = scapix::jni;
using namespace scapix::java_api;

jni::ref<java::lang::String> class1_function1(jni::ref<jni::object<"com/scapix/example1/Class1">>, jni::ref<jni::array<java::lang::String>>);
jni::ref<java::lang::String> class1_function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>);

using class1_native_methods = jni::native_methods
<
	"com/scapix/example1/Class1",

	jni::native_method("function1", class1_function1),
	jni::native_method("function2", class1_function2)
>;

} // namespace example1
```

### Build

```bash
cmake --preset default
cmake --build build/default
```
