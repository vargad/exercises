cmake_minimum_required(VERSION 3.5)
project(recursive_list_reverse)

add_compile_options(-Wall -Wextra -Wdisabled-optimization --coverage)
set(CMAKE_CXX_STANDARD 14)

add_executable(reverse reverse.cpp)
add_executable(reverse2 reverse2.cpp)

target_link_libraries(reverse --coverage)
target_link_libraries(reverse2 --coverage)

add_custom_target(cppcheck VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS reverse reverse2
    COMMAND cppcheck --suppress=missingIncludeSystem
        "--template=[{severity}] {file}:{line} {message} ({id}) {callstack}"
        --enable=warning,performance,portability,style,information
        reverse.cpp reverse2.cpp )

