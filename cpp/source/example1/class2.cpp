#include <example1/class2.h>

namespace example1 {

jni::ref<java::lang::String> class2::function1(jni::ref<jni::array<java::lang::String>>)
{
	return "class2::function1 - hello from C++ " + member;
}

jni::ref<java::lang::String> class2::function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>)
{
	return "class2::function2 - hello from C++";
}

void class2::finalize()
{
	delete this;
}

} // namespace example1
