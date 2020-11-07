cmake_minimum_required(VERSION 3.14)

project(recursive)

add_compile_options(/std:c++latest /constexpr:depth1024)

add_subdirectory(recursive)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE recursive)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE recursive)
