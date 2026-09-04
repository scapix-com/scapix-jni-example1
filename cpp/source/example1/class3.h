#ifndef SCAPIX_JNI_EXAMPLE1_CLASS3_H
#define SCAPIX_JNI_EXAMPLE1_CLASS3_H

#include <scapix/core/immortal.h>
#include <scapix/jni/native_method.h>
#include <scapix/java_api/java/lang/String.h>

namespace example1 {

namespace jni = scapix::jni;
using namespace scapix::java_api;

// Implement native methods as (non-static) C++ member functions.
// This can be done when Java object has assisiated C++ object.
// We provide convert_this() function to convert Java object to corresponding C++ object,
// in this case using map of java objects to C++ objects.

class class3
{
public:

	jni::ref<java::lang::String> function1(jni::ref<jni::array<java::lang::String>>);
	static jni::ref<java::lang::String> function2(jni::ref<jni::class_>, jni::ref<jni::array<java::lang::String>>);

	using native_methods = jni::native_methods
	<
		"com/scapix/example1/Class3",

		jni::native_method("function1", &class3::function1),
		jni::native_method("function2", &class3::function2)
	>;

	std::string member = "class3 member";
};


// C++ destructors for global (static) objects are called when JNI API is no longer available.
// When such objects store owning references (global_ref or weak_ref), they should be declared "immortal",
// to prevent destructor execution.

inline scapix::immortal<std::unordered_map<jni::weak_ref<jni::object<"com/scapix/example1/Class3">>, std::unique_ptr<class3>>> object_map;

} // namespace example1

namespace scapix::jni {

// This example creates associated C++ object on the first native call for a Java object.
// Alternatively, Java and associated C++ object could be created and inserted into map by some other code
// and convert_this would perform lookup only.

template <std::same_as<example1::class3> T>
T& convert_this(jni::ref<object<"com/scapix/example1/Class3">> x)
{
	auto i = ::example1::object_map.try_emplace(x);

	if (!i.first->second)
		i.first->second = std::make_unique<example1::class3>();

	return *i.first->second;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_EXAMPLE1_CLASS3_H
