#include "data.hpp"

data::data()
{
    feature_vector = new std::vector<uint8_t>;
    label = 0;
    enum_label = 0;
}

data::~data()
{
    delete feature_vector;
}

void data::set_feature_vector(std::vector<uint8_t> *feature_vector)
{
    this->feature_vector = feature_vector;
}

void data::append_to_feature_vector(uint8_t value)
{
    feature_vector->push_back(value);
}

void data::set_label(uint8_t label)
{
    this->label = label;
}

void data::set_enum_label(int enum_label)
{
    this->enum_label = enum_label;
}

int data::get_feature_vector_size()
{
    return feature_vector->size();
}

uint8_t data::get_label()
{
    return label;
}

int data::get_enum_label()
{
    return enum_label;
}

std::vector<uint8_t> *data::get_feature_vector()
{
    return feature_vector;
}
