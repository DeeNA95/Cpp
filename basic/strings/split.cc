#include "strings.h"
#include <cctype>
#include <vector>

// myversion
std::vector<std::string> split(const std::string &str) {
  std::string::size_type i = 0;
  std::string::size_type j = 0;
  std::vector<std::string> words;
  std::string::size_type size = str.size();

  // using 2 pointer algo
  while (i < size) {

    while (j <= size - 1) {

      if (std::isspace(static_cast<unsigned char>(str[j]))) {
        std::string sub = str.substr(i, j - i);
        words.push_back(sub);
        i = j + 1;
        j++;
      } else if (j == size - 1) {
        std::string sub = str.substr(i, j + 1 - i);
        words.push_back(sub);
        i = j + 1;
        j++;
      } else {
        j++;
      }
    }
  }
  return words;
}

std::vector<std::string> split_book(const std::string &str) {

  std::vector<std::string> words;

  typedef std::string::size_type string_size;

  string_size i = 0;

  while (i != str.size()) {
    // if i is a space, increment i
    while (i != str.size() && std::isspace(str[i]))
      ++i;

    string_size j = i;
    while (j != str.size() && !std::isspace(str[j]))
      j++;

    if (i != j) {
      words.push_back(str.substr(i, j - i));
      i = j;
    }
  }
  return words;
}
