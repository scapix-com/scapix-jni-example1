#ifndef SCAPIX_JNI_EXAMPLE1_CLASS2_H
#define SCAPIX_JNI_EXAMPLE1_CLASS2_H

#include <scapix/jni/native_method.h>
#include <scapix/java_api/java/lang/String.h>

namespace example1 {

namespace jni = scapix::jni;
using namespace scapix::java_api;

// Implement native methods as (non-static) C++ member functions.
// This can be done when Java object has assisiated C++ object.
// We provide convert_this() function to convert Java object to corresponding C++ object,
// in this case using stored "ptr" field.

class class2
{
public:

	jni::ref<java::lang::String> function1(jni::ref<jni::array<java::lang::String>>);
	static jni::ref<java::lang::String> function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>);
	void finalize();

	using native_methods = jni::native_methods
	<
		"com/scapix/example1/Class2",

		jni::native_method("function1", &class2::function1),
		jni::native_method("function2", &class2::function2),
		jni::native_method("finalize", &class2::finalize)
	>;

	std::string member = "class2 member";
};

} // namespace example1

namespace scapix::jni {

// This example creates associated C++ object on the first native call for a Java object.
// Alternatively, Java and associated C++ object could be created together by some other code
// and convert_this would perform conversion only.

template <std::same_as<example1::class2> T>
T& convert_this(jni::ref<object<"com/scapix/example1/Class2">> x)
{
	if (auto p = reinterpret_cast<example1::class2*>(x->get_field<"ptr", jlong>()))
		return *p;

	// deleted in class2::finalize()

	auto p = new example1::class2();
	x->set_field<"ptr", jlong>(reinterpret_cast<jlong>(p));
	return *p;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_EXAMPLE1_CLASS2_H
