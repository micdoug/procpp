add_executable(crash_course main.cc)
target_include_directories(crash_course PRIVATE .)
target_link_libraries(crash_course PRIVATE fmt::fmt GSL bindings)