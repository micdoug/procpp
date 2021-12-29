#include <bindings/format.h>

#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include "database.h"
#include "employee.h"

using records::Database;
using records::Employee;

enum class MenuOption : int {
  Hire = 1,
  Fire = 2,
  Promote = 3,
  ListAll = 4,
  ListCurrent = 5,
  ListFormer = 6,
  Quit = 0,
  Unknown = -1,
};

std::optional<int> ReadInt(std::istream& stream) {
  std::string line_input;
  std::getline(stream, line_input);
  try {
    return std::stoi(line_input);
  } catch (...) {
    return std::nullopt;
  }
}

MenuOption DisplayMenu() {
  std::cout << std::endl;
  std::cout << "Employee Database" << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << "1) Hire a new employee" << std::endl;
  std::cout << "2) Fire an employee" << std::endl;
  std::cout << "3) Promote an employee" << std::endl;
  std::cout << "4) List all employees" << std::endl;
  std::cout << "5) List all current employees" << std::endl;
  std::cout << "6) List all former employees" << std::endl;
  std::cout << "0) Quit" << std::endl;
  std::cout << std::endl;
  std::cout << "---> ";
  auto selection{ReadInt(std::cin)};
  if (!selection) {
    return MenuOption::Unknown;
  }

  return static_cast<MenuOption>(selection.value());
}
void DoHire(Database& db) {
  std::string first_name;
  std::string last_name;

  std::cout << "First name? ";
  std::cin >> first_name;

  std::cout << "Last name? ";
  std::cin >> last_name;

  auto& employee{db.AddEmployee(first_name, last_name)};
  std::cout << std::format("Hired employee {} {} with employee number {}.",
                           employee.first_name(), employee.last_name(),
                           employee.employee_number())
            << std::endl;
}
void DoFire(Database& db) {
  int employee_number;
  std::cout << "Employee number? ";
  std::cin >> employee_number;

  try {
    auto& employee{db.GetEmployee(employee_number)};
    employee.Fire();
    std::cout << std::format("Employee {} terminated.", employee_number)
              << std::endl;
  } catch (const std::logic_error& exception) {
    std::cerr << std::format("Unable to terminate employee: {}",
                             exception.what())
              << std::endl;
  }
}
void DoPromote(Database& db) {
  int employee_number;

  std::cout << "Employee number? ";
  std::cin >> employee_number;

  int raise_amount;
  std::cout << "How much of a raise? ";
  std::cin >> raise_amount;

  try {
    auto& emp{db.GetEmployee(employee_number)};
    emp.Promote(raise_amount);
  } catch (const std::logic_error& exception) {
    std::cerr << std::format("Unable to promote employee: {}", exception.what())
              << std::endl;
  }
}

int main() {
  Database employee_db{};
  bool done{false};
  while (!done) {
    switch (DisplayMenu()) {
      case MenuOption::Quit:
        done = true;
        break;
      case MenuOption::Hire:
        DoHire(employee_db);
        break;
      case MenuOption::Fire:
        DoFire(employee_db);
        break;
      case MenuOption::Promote:
        DoPromote(employee_db);
        break;
      case MenuOption::ListAll:
        employee_db.DisplayAll();
        break;
      case MenuOption::ListCurrent:
        employee_db.DisplayCurrent();
        break;
      case MenuOption::ListFormer:
        employee_db.DisplayFormer();
        break;
      default:
        std::cerr << "Unknown command." << std::endl;
        break;
    }
  }
  return 0;
}
