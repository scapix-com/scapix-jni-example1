add_custom_target(example1_run ALL
  COMMAND ${Java_JAVA_EXECUTABLE} -Djava.library.path=$<TARGET_FILE_DIR:example1_cpp> -jar $<TARGET_PROPERTY:example1_java,JAR_FILE>
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Running Java example"
  VERBATIM
)

add_dependencies(example1_run example1_java example1_cpp)
