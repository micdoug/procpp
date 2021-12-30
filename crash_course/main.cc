#include <bindings/format.h>

#include <charconv>
#include <cmath>
#include <compare>
#include <cstddef>  // this is where std::byte is defined
#include <cstdint>  // this is where int8, uint8 ... are defined
#include <gsl/narrow>
#include <gsl/pointers>
#include <iostream>
#include <limits>

#include "employee.h"

void foo() {
  // Every function has a __func__ variable with its name.
  std::cout << std::format("You are calling the function '{}'", __func__)
            << std::endl;
}

void bar(gsl::not_null<int*> number) {
  std::cout << std::format("You called the function {} with the value {}",
                           __func__, *number)
            << std::endl;
}

[[nodiscard("You can't ignore the sum result")]] int sum(int a, int b) {
  return a + b;
}

int main() {
  int unInitializedInt;
  int initializedInt{42};
  std::cout << std::format("Uninitialized int: {}", unInitializedInt)
            << std::endl;
  std::cout << std::format("Initialized int: {}", initializedInt) << std::endl;

  std::byte unInitializedByte;
  std::byte initializedByte{42};
  std::cout << std::format("Uninitialized byte: {}", unInitializedByte)
            << std::endl;
  std::cout << std::format("Initialized byte: {}", initializedByte)
            << std::endl;

  std::cout << "Showing limits:\n";
  std::cout << std::format("Max int value: {}\n",
                           std::numeric_limits<int>::max());
  std::cout << std::format("Min int value: {}\n",
                           std::numeric_limits<int>::min());

  std::cout << std::format("Max uint8_t: {}\n",
                           std::numeric_limits<uint8_t>::max());
  std::cout << std::format("Max uint16_t: {}\n",
                           std::numeric_limits<uint16_t>::max());
  std::cout << std::format("Max uint32_t: {}\n",
                           std::numeric_limits<uint32_t>::max());
  std::cout << std::format("Max uint64_t: {}\n",
                           std::numeric_limits<uint64_t>::max());

  std::cout << std::format("0/0 is NaN: {}\n", (std::isnan(0.0 / 0.0)));
  std::cout << std::format("1/0 is NaN: {}\n", (std::isnan(1.0 / 0.0)));
  std::cout << std::format("1/0 = {}\n", 1.0 / 0.0);
  std::cout << std::format("-1/0 = {}\n", -1.0 / 0.0);

  Employee employee{
      .first_initial = 'M',
      .last_initial = 'S',
      .employee_number = 1,
      .salary = 1'000,
  };
  std::cout << std::format("Employee: {}\n", employee);

  if (int number{42}; number > 40) {
    std::cout << "It works\n";
  }

  std::strong_ordering result = 42 <=> 10;

  if (std::is_lt(result)) {
    std::cout << "It is less than" << std::endl;
  } else if (std::is_gt(result)) {
    std::cout << "It is greater than" << std::endl;
  } else if (std::is_eq(result)) {
    std::cout << "It is equal" << std::endl;
  }

  std::cout << std::endl;
  foo();

  std::cout << std::endl;
  // sum(2, 2);  // doesn't compile because the return value is discarded

  for (std::array<int, 3> arr{1, 2, 3}; const auto& num : arr) {
    std::cout << num << std::endl;
  }

  [[maybe_unused]] int number = gsl::narrow_cast<int>(3.14);

  const size_t buffer_size = 50;
  std::string converted_number{buffer_size, ' '};

  std::to_chars(converted_number.data(),
                converted_number.data() + converted_number.size(), 42);
  std::cout << std::format("The converted number is: {}", converted_number)
            << std::endl;

  int back_to_int{};

  std::from_chars(converted_number.data(),
                  converted_number.data() + converted_number.size(),
                  back_to_int);

  std::cout << std::format("Back to int value is: {}", back_to_int)
            << std::endl;
  return 0;
}
