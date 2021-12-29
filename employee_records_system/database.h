#pragma once

#include <string>
#include <vector>

#include "employee.h"

namespace records {
const int kFirstEmployeeNumber{1'000};

class Database {
 public:
  Employee& AddEmployee(const std::string& first_name,
                        const std::string& last_name);
  Employee& GetEmployee(const int employee_number);
  Employee& GetEmployee(const std::string& first_name,
                        const std::string& last_name);

  void DisplayAll() const;
  void DisplayCurrent() const;
  void DisplayFormer() const;

 private:
  std::vector<Employee> employees_;
  int next_employee_number_{kFirstEmployeeNumber};
};

}  // namespace records
