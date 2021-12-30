add_executable(strings_practice main.cc)
target_link_libraries(strings_practice PRIVATE bindings)

add_executable(sort_words sort_words.cc)
target_link_libraries(sort_words PRIVATE bindings)

add_executable(haystack haystack.cc)
target_link_libraries(haystack PRIVATE bindings)

add_executable(format_numbers format_numbers.cc)
target_link_libraries(format_numbers PRIVATE bindings)