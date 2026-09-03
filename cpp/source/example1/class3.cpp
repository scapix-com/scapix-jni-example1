#include <example1/class3.h>

namespace example1 {

jni::ref<java::lang::String> class3::function1(jni::ref<jni::array<java::lang::String>>)
{
	return "class3::function1 - hello from C++ " + member;
}

jni::ref<java::lang::String> class3::function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>)
{
	return "class3::function2 - hello from C++";
}

} // namespace example1
