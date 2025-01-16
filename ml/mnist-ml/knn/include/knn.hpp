#ifndef __KNN_H_
#define __KNN_H_

#include <vector>
#include <map>
#include "data.hpp"

class knn {
private:
    int k;
    std::vector<data *> *training_data;
    std::vector<data *> *testing_data;
    std::vector<data *> *validation_data;
    std::vector<data *> k_nearest;

public:
    knn(int val);
    knn();
    ~knn();

    void find_k_nearest(data *query_point);
    void set_training_data(std::vector<data *> *vect);
    void set_test_data(std::vector<data *> *vect);
    void set_validation_data(std::vector<data *> *vect);
    void set_k(int val);
    double predict(bool regression_mode = false, bool weighted = false);
    double calc_distance(data *query_point, data *input);
    double validate_performance();
    double test_performance();
};

#endif
