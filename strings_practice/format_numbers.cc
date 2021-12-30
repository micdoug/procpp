/* Write a program that asks the user to enter an unknown number of
 * floating-point numbers and stores all numbers in a vector. Each number should
 * be typed followed by an enter. Stop asking new numbers when the user inputs
 * the number 0. Format all numbers in a table with a couple of columns where
 * each column formats a number in a different way.
 */

#include <bindings/format.h>

#include <iostream>
#include <string>
#include <vector>

std::vector<double> ReadNumbers() {
  std::vector<double> numbers{};
  while (true) {
    std::cout << "Enter a number: ";
    double received_number{};
    std::cin >> received_number;
    if (received_number == 0) {
      return numbers;
    }
    numbers.push_back(received_number);
  }
}

int main() {
  const auto& numbers{ReadNumbers()};
  for (const auto& number : numbers) {
    std::cout << std::format("{0:.2f}\t{0:e}\t{0:E}\t{0:a}", number)
              << std::endl;
  }
  return 0;
}
