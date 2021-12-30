/* Write a program that asks the user for a source string (=haystack), a
 * string to find (=needle) in the source string, and a replacement string.
 * Write a function with three parameters - the haystack, needle, and the
 * replacement string - that returns the copy of the haystack with all needles
 * replaced with the replacement string. Use only std::string, no
 * std::string_view.
 */

#include <bindings/format.h>

#include <iostream>
#include <string>
#include <string_view>

std::string Replace(const std::string_view haystack, std::string_view needle,
                    const std::string_view replacement) {
  std::string copy{haystack};
  while (true) {
    const std::size_t needle_index{copy.find(needle)};
    if (needle_index == std::string::npos) {
      break;
    }
    copy.replace(needle_index, needle.size(), replacement);
  }
  return copy;
}

int main() {
  std::string haystack;
  std::string needle;
  std::string replacement;
  std::cout << "Enter a source string: ";
  std::getline(std::cin, haystack);
  std::cout << "Enter the needle word: ";
  std::getline(std::cin, needle);
  std::cout << "Enter the replacement word: ";
  std::getline(std::cin, replacement);
  std::cout << Replace(haystack, needle, replacement) << std::endl;
  return 0;
}
