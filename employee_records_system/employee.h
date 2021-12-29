#pragma once

#include <string>

namespace records {

const int kDefaultRaiseAndDemeritAmount{1'000};
const int kDefaultStartingSalary{30'000};

class Employee {
 public:
  Employee(const std::string& first_name, const std::string& last_name);

  void Promote(const int raise_amount = kDefaultRaiseAndDemeritAmount);
  void Demote(const int demerit_amount = kDefaultRaiseAndDemeritAmount);

  // Hires or rehires the employee
  void Hire();
  // Dismisses the employee
  void Fire();
  // Output employee info to the console.
  void Display() const;

  void set_first_name(const std::string& first_name);
  const std::string& first_name() const;

  void set_last_name(const std::string& last_name);
  const std::string& last_name() const;

  void set_employee_number(const int employee_number);
  int employee_number() const;

  void set_salary(const int salary);
  int salary() const;

  bool is_hired() const;

 private:
  std::string first_name_;
  std::string last_name_;
  int employee_number_{-1};
  int salary_{kDefaultStartingSalary};
  bool hired_{false};
};
}  // namespace records
