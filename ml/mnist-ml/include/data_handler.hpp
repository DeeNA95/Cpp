#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H

#include <fstream>
#include <stdint.h>
#include <vector>
#include "data.hpp"
#include "string.h"
#include <map>
#include <unordered_set>


// logic for data reading
class data_handler
{
    std::vector<data *> * data_array;
    std::vector<data *> * training_data;
    std::vector<data *> * testing_data;
    std::vector<data *> * validation_data;

    int num_classes;
    int feature_vector_size;
    std::map<uint8_t, int> class_map;

    const double TRAINING_DATA_RATIO = 0.75;
    const double TESTING_DATA_RATIO = 0.15;
    const double VALIDATION_DATA_RATIO = 0.1;

    public:
    data_handler();
    ~data_handler();

    void read_feature_vector(std::string file_path);
    void read_feature_labels(std::string file_path);
    void split_data();
    void count_classes();

    uint32_t convert_to_lil_endian(const unsigned char* bytes);

    std::vector<data *> * get_training_data();
    std::vector<data *> * get_testing_data();
    std::vector<data *> * get_validation_data();

};

#endif
