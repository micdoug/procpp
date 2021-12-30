/* Write a program that asks the user for two strings and then prints them out
 * in alphabetical order, using the three-way comparison operator. To ask the
 * user for a string, you can use the std::cin stream.
 */
#include <bindings/format.h>

#include <compare>
#include <iostream>
#include <string>

int main() {
  std::string first_word;
  std::string second_word;

  std::cout << "Enter the first word: ";
  std::cin >> first_word;

  std::cout << "Enter the second word: ";
  std::cin >> second_word;

  const std::strong_ordering order_result{first_word <=> second_word};

  if (std::is_lteq(order_result)) {
    std::cout << std::format("'{}' | '{}'", first_word, second_word)
              << std::endl;
  } else {
    std::cout << std::format("'{}' | '{}'", second_word, first_word)
              << std::endl;
  }
  return 0;
}
