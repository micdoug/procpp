#pragma once

#include <bindings/format.h>

struct Employee {
  char first_initial;
  char last_initial;
  int employee_number;
  int salary;
};

template <>
struct std::formatter<Employee> {
  template <typename FormatContext>
  auto format(const Employee& employee, FormatContext& ctx)
      -> decltype(ctx.out()) {
    return format_to(
        ctx.out(),
        "Employee(firstInitial={}, lastInitial={}, number={}, salary={})",
        employee.first_initial, employee.last_initial, employee.employee_number,
        employee.salary);
  }

  constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    return ctx.end();
  }
};
