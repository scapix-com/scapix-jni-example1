cmake_minimum_required(VERSION 3.20...3.27)

project(scapix_jni_example1)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.5.0.tar.gz
  URL_HASH SHA256=0b5cfb0d88e8a9b7801b8c423d6713785ddce65692f35d9081a56695a6cfaaea
)
FetchContent_MakeAvailable(cmodule)

add_subdirectory("cpp")
add_subdirectory("java")
add_subdirectory("run")
