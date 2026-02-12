#include "strings.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
// this function will take a vector of strings and combine them with a frame
// function to find longest string to make frame full surround

std::string::size_type width(const std::vector<std::string> &v) {
  std::string::size_type maxlen = 0;
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    maxlen = std::max(maxlen, v[i].size());
  };
  return maxlen;
}

// my frame NB not as efficient as the book
std::string frame(const std::vector<std::string> &v) {
  std::string::size_type w = width(v);

  std::string output(w + 4, '*'); // populate output with w+4 *
  output += '\n';
  for (int i = 0; i != v.size();
       ++i) { // should be vector<string>::size_type but int is castable
    std::string lined = "*" + v[i];
    if (w != lined.size()) {
      std::string::size_type padd = w + 3 - lined.size(); // minus 1 for end *

      std::string spaces(padd, ' ');
      lined += spaces;
    };
    output += lined + "*\n";
  }
  std::string last_line(w + 4, '*');
  output += last_line;

  return output;
}

// book frame
//
std::vector<std::string> frame_book(const std::vector<std::string> &v) {
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);
  std::string border(maxlen + 4, '*');

  ret.push_back(border);

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + std::string(maxlen - v[i].size(), ' ') + " *");
  }
  ret.push_back(border);
  return ret;
}

// vertical concatenate
std::vector<std::string> vcat(const std::vector<std::string> &top,
                              const std::vector<std::string> &bottom) {
  std::vector<std::string> ret = top;

  for (int i = 0; i != bottom.size(); ++i) {
    ret.push_back(bottom[i]);
  }

  return ret;
}

// better because it copies as an iterator
std::vector<std::string> vcat_book(const std::vector<std::string> &top,
                                   const std::vector<std::string> &bottom) {
  std::vector<std::string> ret = top;

  // for (std::vector<std::string>::const_iterator it = bottom.begin();
  //      it != bottom.end(); ++it) {
  //   ret.push_back(*it);
  // }
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

std::vector<std::string> hcat(const std::vector<std::string> &left,
                              const std::vector<std::string> &right) {
  std::vector<std::string>::size_type left_size, right_size;
  left_size = left.size();
  right_size = right.size();
  std::vector<std::string>::size_type len = std::max(left_size, right_size);
  std::vector<std::string> ret;
  std::vector<std::string> l_copy = left;
  if (right_size > left_size) {

    for (int i = 0; i < right_size - left_size; ++i) {
      l_copy.push_back(" ");
    }
  }

  for (int it; it < l_copy.size(); ++it) {
    std::string line = l_copy[it] + right[it];
    ret.push_back(line);
  }

  return ret;
}
