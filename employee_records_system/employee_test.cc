#include "employee.h"

#include <gtest/gtest.h>

using records::Employee;
using records::kDefaultRaiseAndDemeritAmount;
using records::kDefaultStartingSalary;

TEST(EmployeeTest, BuildANewEmployee) {
  Employee emp{"Jane", "Doe"};
  EXPECT_EQ(emp.first_name(), "Jane");
  EXPECT_EQ(emp.last_name(), "Doe");
  EXPECT_FALSE(emp.is_hired());
  EXPECT_EQ(emp.salary(), kDefaultStartingSalary);
  EXPECT_EQ(emp.employee_number(), -1);
}

TEST(EmployeeTest, HireEmployee) {
  Employee emp{"Michael", "Silva"};
  emp.Hire();
  EXPECT_TRUE(emp.is_hired());
}

TEST(EmployeeTest, FireEmployee) {
  Employee emp{"Michael", "Silva"};
  emp.Fire();
  EXPECT_FALSE(emp.is_hired());
}

TEST(EmployeeTest, SetFirstName) {
  Employee emp{"first", "last"};
  emp.set_first_name("Michael");
  EXPECT_EQ(emp.first_name(), "Michael");
}

TEST(EmployeeTest, SetLastName) {
  Employee emp{"first", "last"};
  emp.set_last_name("Silva");
  EXPECT_EQ(emp.last_name(), "Silva");
}

TEST(EmployeeTest, SetEmployeeNumber) {
  Employee emp{"first", "last"};
  emp.set_employee_number(42);
  EXPECT_EQ(emp.employee_number(), 42);
}

TEST(EmployeeTest, SetSalary) {
  Employee emp{"first", "last"};
  emp.set_salary(99'999);
  EXPECT_EQ(emp.salary(), 99'999);
}
