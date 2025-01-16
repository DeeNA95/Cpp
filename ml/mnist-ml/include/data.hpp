#ifndef DATA_H
#define DATA_H

#include <vector>
#include "stdio.h"
#include "stdint.h"

class data
{
  std::vector<uint8_t> * feature_vector;
  uint8_t label;
  int enum_label;
  double distance;

  public:
  data();
  ~data();
  void set_feature_vector(std::vector<uint8_t> *feature_vector);
  void append_to_feature_vector(uint8_t value);
  void set_label(uint8_t);
  void set_enum_label(int);
  void set_distance(double val);
  double get_distance() const;

  int get_feature_vector_size();
  uint8_t get_label();
  int get_enum_label();

  std::vector<uint8_t> * get_feature_vector();
};

#endif
