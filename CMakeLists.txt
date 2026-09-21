cmake_minimum_required(VERSION 3.20...3.27)

project(scapix_jni_example1)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.6.0.tar.gz
  URL_HASH SHA256=7ee432c13bf91d3c86d2ab675ba379cea079e39b9efbe183f2ab4e7b479cee90
)
FetchContent_MakeAvailable(cmodule)

add_subdirectory("cpp")
add_subdirectory("java")
add_subdirectory("run")
