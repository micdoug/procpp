#include "employee.h"

#include <bindings/format.h>

#include <iostream>

namespace records {

Employee::Employee(const std::string& first_name, const std::string& last_name)
    : first_name_{first_name}, last_name_{last_name} {}

void Employee::Promote(const int raise_amount) {
  set_salary(salary() + raise_amount);
}

void Employee::Demote(const int demerit_amount) {
  set_salary(salary() - demerit_amount);
}

void Employee::Hire() { hired_ = true; }

void Employee::Fire() { hired_ = false; }

void Employee::Display() const {
  std::cout << std::format("Employee: {}, {}", last_name(), first_name())
            << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << (is_hired() ? "Current Employee" : "Former Employee")
            << std::endl;
  std::cout << std::format("Employee Number: {}", employee_number())
            << std::endl;
  std::cout << std::format("Salary: ${}", salary()) << std::endl;
  std::cout << std::endl;
}

void Employee::set_first_name(const std::string& first_name) {
  first_name_ = first_name;
}

const std::string& Employee::first_name() const { return first_name_; }

void Employee::set_last_name(const std::string& last_name) {
  last_name_ = last_name;
}

const std::string& Employee::last_name() const { return last_name_; }

void Employee::set_employee_number(const int employee_number) {
  employee_number_ = employee_number;
}

int Employee::employee_number() const { return employee_number_; }

void Employee::set_salary(const int salary) { salary_ = salary; }

int Employee::salary() const { return salary_; }

bool Employee::is_hired() const { return hired_; }

}  // namespace records
