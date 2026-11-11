cmake_minimum_required(VERSION 3.20...3.27)
project(example1_cpp)

add_library(example1_cpp SHARED)

file(GLOB_RECURSE sources "source/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

target_sources(example1_cpp PRIVATE ${sources})
target_include_directories(example1_cpp PRIVATE "source")

# optionally override API selection
# set(SCAPIX_JAVA_API "jdk-11" CACHE STRING "" FORCE)

find_package(ScapixJavaAPI REQUIRED)
target_link_libraries(example1_cpp PRIVATE scapix::java_api)
scapix_java_api_source_group()
