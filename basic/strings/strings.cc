#include "strings.h"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::string query =
      (argc > 1)
          ? argv[1]
          : "   This Is the Standard String We Will Use For Testing.    ";
  std::vector<std::string> output, output2;

  output = split(query);
  std::cout << "My Implementation" << "\n\n";
  for (std::vector<std::string>::iterator i = output.begin(); i < output.end();
       ++i) {
    printf("%s\n", i->c_str());
  }

  std::cout << "\n\nBook's Implementation" << "\n\n";
  output2 = split_book(query);
  for (std::vector<std::string>::iterator i = output2.begin();
       i < output2.end(); ++i) {
    printf("%s\n", i->c_str());
  }

  // frame it
  std::cout << "\nMY FRAME" << '\n';
  std::string framed = frame(output2);
  std::cout << framed << '\n';

  // book frame
  std::cout << "\nBOOK FRAME" << '\n';

  std::vector<std::string> framed2 = frame_book(output2);
  for (std::vector<std::string>::iterator i = framed2.begin();
       i < framed2.end(); ++i) {
    printf("%s\n", i->c_str());
  }

  // vert concat
  std::cout << "VCAT ME" << '\n';
  std::vector<std::string> vcatted = vcat(output2, framed2);
  for (std::vector<std::string>::iterator i = vcatted.begin();
       i < vcatted.end(); ++i) {
    printf("%s\n", i->c_str());
  }

  std::cout << "VCAT BOOK" << '\n';
  std::vector<std::string> vcatted2 = vcat_book(output2, framed2);
  for (std::vector<std::string>::iterator i = vcatted2.begin();
       i < vcatted2.end(); ++i) {
    printf("%s\n", i->c_str());
  }

  std::cout << "HCAT" << '\n';
  std::vector<std::string> hcatted = hcat(framed2, output2);
  for (std::vector<std::string>::iterator i = hcatted.begin();
       i < hcatted.end(); ++i) {
    printf("%s\n", i->c_str());
  }

  return 0;
}
