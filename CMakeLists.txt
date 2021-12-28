cmake_minimum_required(VERSION 3.15.0)

project(procpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# add third party libraries
add_subdirectory(external/fmt)
add_subdirectory(external/gsl)

# add bindings to cpp format library
add_subdirectory(bindings)

add_subdirectory(crash_course)