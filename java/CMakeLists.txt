cmake_minimum_required(VERSION 3.20...3.27)
project(example1_java)

include(UseJava)

file(GLOB_RECURSE sources "*.java")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "java" FILES ${sources})

get_target_property(scapix_jni_sources scapix::jni INTERFACE_SOURCES)

add_jar(example1_java SOURCES ${sources} ${scapix_jni_sources} MANIFEST ${CMAKE_CURRENT_SOURCE_DIR}/MANIFEST.MF)
