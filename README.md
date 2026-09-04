# Example1 for [Scapix JNI](https://www.scapix.com/jni/)

[Scapix JNI](https://www.scapix.com/jni/) is a modern C++20 library for Java Native Interface ([JNI](https://docs.oracle.com/en/java/javase/25/docs/specs/jni/)).
It provides type-safe APIs and automatic resource management, with zero runtime overhead compared to manually written JNI code.

Implementing Java native methods in C++

- class1 - example using C++ free functions.
- class2 - example using C++ non-static member functions, with "ptr" field in Java objects.
- class3 - example using C++ non-static member functions, with std::unordered_map of Java refs to C++ objects.

Build:

```bash
cmake -B build
cmake --build build
```
