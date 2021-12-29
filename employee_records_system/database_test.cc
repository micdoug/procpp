#include "database.h"

#include <gtest/gtest.h>

using records::Database;
using records::Employee;

TEST(DatabaseTest, AddEmployee) {
  Database database{};
  const auto& employee = database.AddEmployee("John", "Doe");

  EXPECT_EQ(employee.first_name(), "John");
  EXPECT_EQ(employee.last_name(), "Doe");
  EXPECT_TRUE(employee.is_hired());
  EXPECT_GT(employee.employee_number(), 0);
}

TEST(DatabaseTest, AddMultipleEmployeeIncreasesEmployeeNumber) {
  Database database{};
  const auto& emp1 = database.AddEmployee("first", "employee");
  const auto& emp2 = database.AddEmployee("second", "employee");

  EXPECT_LT(emp1.employee_number(), emp2.employee_number());
}

TEST(DatabaseTest, GetEmployeeByEmployeeNumber) {
  Database database{};
  const auto& added_employee = database.AddEmployee("John", "Doe");

  const auto& employee = database.GetEmployee(added_employee.employee_number());

  EXPECT_EQ(&added_employee, &employee);
}

TEST(DatatabaseTest, GetEmployeeByEmployeeNumberNotFound) {
  Database database{};

  EXPECT_THROW({ database.GetEmployee(42); }, std::logic_error);
}

TEST(DatabaseTest, GetEmployeeByFirstAndLastName) {
  Database database{};
  const auto& added_employee = database.AddEmployee("John", "Doe");

  const auto& employee = database.GetEmployee("John", "Doe");
  EXPECT_EQ(&added_employee, &employee);
}

TEST(DatabaseTest, GetEmployeeByFirstAndLastNameNotFound) {
  Database database{};

  EXPECT_THROW({ database.GetEmployee("John", "Doe"); }, std::logic_error);
}


