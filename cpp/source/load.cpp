#include <scapix/jni/module.h>

#include <example1/class1.h>
#include <example1/class2.h>
#include <example1/class3.h>

namespace jni = scapix::jni;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	return jni::on_load(vm, reserved, []
	{
		example1::class1_native_methods::register_();
		example1::class2::native_methods::register_();
		example1::class3::native_methods::register_();
	});
}
