#include <example1/class1.h>

namespace example1 {

jni::ref<java::lang::String> class1_function1(jni::ref<jni::object<"com/scapix/example1/Class1">>, jni::ref<jni::array<java::lang::String>>)
{
	return "class1_function1 - hello from C++";
}

jni::ref<java::lang::String> class1_function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>)
{
	return "class1_function2 - hello from C++";
}

} // namespace example1
