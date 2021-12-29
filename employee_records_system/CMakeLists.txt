add_executable(employee_records_system 
    main.cc
    employee.cc
    database.cc
)
target_link_libraries(employee_records_system PRIVATE bindings)
target_include_directories(employee_records_system PRIVATE .)

# add test target
add_executable(employee_records_system_tests
    employee_test.cc
    employee.cc
    database.cc
    database_test.cc
)
target_link_libraries(employee_records_system_tests gtest_main bindings)
target_include_directories(employee_records_system_tests PRIVATE .)
gtest_discover_tests(employee_records_system_tests)