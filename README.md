# scapix-jni-example1 for [Scapix JNI](https://www.scapix.com/jni/)

Implementing Java native methods in C++

<class1.h> - using C++ free functions.
<class2.h> - using C++ non-static member functions, with "ptr" field in Java objects.
<class3.h> - using C++ non-static member functions, with std::unordered_map of Java refs to C++ objects.

Build:

```bash
cmake -B build
cmake --build build
```
