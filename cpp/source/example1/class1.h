#ifndef SCAPIX_JNI_EXAMPLE1_CLASS1_H
#define SCAPIX_JNI_EXAMPLE1_CLASS1_H

#include <scapix/jni/native_method.h>
#include <scapix/java_api/java/lang/String.h>

namespace example1 {

namespace jni = scapix::jni;
using namespace scapix::java_api;

// Implement native methods as free functions.
// For an instance method, the first parameter must be ref<object<"com/scapix/example1/Class1">> (or compatible).
// For a static method, the first parameter must be ref<class_> (or compatible).
// JNI signature is deduced automatically.

jni::ref<java::lang::String> class1_function1(jni::ref<jni::object<"com/scapix/example1/Class1">>, jni::ref<jni::array<java::lang::String>>);
jni::ref<java::lang::String> class1_function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>);

using class1_native_methods = jni::native_methods
<
	"com/scapix/example1/Class1",

	jni::native_method("function1", class1_function1),
	jni::native_method("function2", class1_function2)
>;

} // namespace example1

#endif // SCAPIX_JNI_EXAMPLE1_CLASS1_H
