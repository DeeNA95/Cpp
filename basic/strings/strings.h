#ifndef STRING_H
#define STRING_H

#include <cstdio>
// #include <iostream>
#include <cctype>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str);
std::vector<std::string> split_book(const std::string &str);
std::string frame(const std::vector<std::string> &str);
std::vector<std::string> frame_book(const std::vector<std::string> &str);
std::vector<std::string> vcat(const std::vector<std::string> &top,
                              const std::vector<std::string> &bottom);

std::vector<std::string> vcat_book(const std::vector<std::string> &top,
                                   const std::vector<std::string> &bottom);

std::vector<std::string> hcat(const std::vector<std::string> &left,
                              const std::vector<std::string> &right);
#endif
