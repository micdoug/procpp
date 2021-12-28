add_library(bindings blank.cc)
target_include_directories(bindings PUBLIC .)
target_link_libraries(bindings PRIVATE fmt::fmt)