#include "database.h"

#include <stdexcept>

namespace records {

Employee& Database::AddEmployee(const std::string& first_name,
                                const std::string& last_name) {
  Employee emp{first_name, last_name};
  emp.set_employee_number(next_employee_number_++);
  emp.Hire();
  employees_.push_back(emp);
  return employees_.back();
}

Employee& Database::GetEmployee(const int employee_number) {
  for (auto& employee : employees_) {
    if (employee.employee_number() == employee_number) {
      return employee;
    }
  }
  throw std::logic_error{"No employee found."};
}

Employee& Database::GetEmployee(const std::string& first_name,
                                const std::string& last_name) {
  for (auto& employee : employees_) {
    if (employee.first_name() == first_name &&
        employee.last_name() == last_name) {
      return employee;
    }
  }
  throw std::logic_error{"No employee found."};
}

void Database::DisplayAll() const {
  for (const auto& employee : employees_) {
    employee.Display();
  }
}

void Database::DisplayCurrent() const {
  for (const auto& employee : employees_) {
    if (employee.is_hired()) {
      employee.Display();
    }
  }
}

void Database::DisplayFormer() const {
  for (const auto& employee : employees_) {
    if (!employee.is_hired()) {
      employee.Display();
    }
  }
}

}  // namespace records
