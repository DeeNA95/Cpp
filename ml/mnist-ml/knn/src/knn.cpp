#include "knn.hpp"
#include <cmath>
#include <map>
#include <limits>
#include "data_handler.hpp"
#include <algorithm>

knn::knn(int val) {
    k = val;
    training_data = nullptr;
    testing_data = nullptr;
    validation_data = nullptr;
}

knn::knn() {
    k = 3;
    training_data = nullptr;
    testing_data = nullptr;
    validation_data = nullptr;
}

knn::~knn() {
}

void knn::find_k_nearest(data *query_point) {
    if (!training_data || training_data->empty()) return;

    std::vector<data *> neighbors(training_data->begin(), training_data->end());
    for (data *d : neighbors) {
        d->set_distance(calc_distance(query_point, d));
    }

    std::partial_sort(neighbors.begin(),
                     neighbors.begin() + std::min(k, (int)neighbors.size()),
                     neighbors.end(),
                     [](data *a, data *b) { return a->get_distance() < b->get_distance(); });

    k_nearest = std::vector<data *>(
        neighbors.begin(),
        neighbors.begin() + std::min(k, (int)neighbors.size())
    );
}

void knn::set_training_data(std::vector<data *> *vect)
{
    training_data = vect;
}

void knn::set_test_data(std::vector<data *> *vect)
{
    testing_data = vect;
}

void knn::set_validation_data(std::vector<data *> *vect)
{
    validation_data = vect;
}

void knn::set_k(int val)
{
    k = val;
}

double knn::predict(bool regression_mode, bool weighted) {
    if (k_nearest.empty()) return -1;

    if (regression_mode) {
        double sum = 0.0;
        double weight_sum = 0.0;

        for (data *d : k_nearest) {
            double weight = weighted ? 1.0 / (d->get_distance() * d->get_distance()) : 1.0;
            sum += weight * d->get_label();
            weight_sum += weight;
        }
        return weighted ? sum / weight_sum : sum / k_nearest.size();
    } else {
        std::map<int, double> class_weights;

        for (data *d : k_nearest) {
            double weight = weighted ? 1.0 / (d->get_distance() * d->get_distance()) : 1.0;
            class_weights[d->get_label()] += weight;
        }

        int predicted_class = -1;
        double max_weight = 0;
        for (const auto& pair : class_weights) {
            if (pair.second > max_weight) {
                max_weight = pair.second;
                predicted_class = pair.first;
            }
        }
        return predicted_class;
    }
}

double knn::calc_distance(data *query_point, data *input)
{
    double distance = 0.0;

    if (query_point->get_feature_vector_size() != input->get_feature_vector_size())
    {
        printf("Error: feature vector sizes do not match\n");
        exit(1);
    }

#ifdef EUCLIDEAN
    // euclidean distance
    for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++)
        distance += pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    return sqrt(distance);

#elif defined MANHATTAN
    // manhattan distance
    for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++)
        distance += abs(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i));
    return distance;

#elif defined MINKOWSKI
    // minkowski distance
    double p = 3.0;
    for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++)
        distance += pow(abs(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i)), p);
    return pow(distance, 1.0 / p);
#else
    // not specified = euclidean
    for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++)
        distance += pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    return sqrt(distance);
#endif
}

double knn::validate_performance()
{
    if (!validation_data || validation_data->empty()) return 0.0;

    int correct = 0;
    int data_index = 0;
    for (data *query_point : *validation_data)
    {
        find_k_nearest(query_point);
        double prediction = predict(false, false);
        if (prediction == query_point->get_label())
            correct++;
        data_index++;
        printf("Validation sample %d: %s\n", data_index, prediction == query_point->get_label() ? "Correct" : "Incorrect");
    }
    printf("Validation accuracy for k = %d: %f\n", k, (double)correct / validation_data->size());
    return (double)correct / validation_data->size();
}

double knn::test_performance()
{
    if (!testing_data || testing_data->empty()) return 0.0;

    int correct = 0;
    int data_index = 0;
    for (data *query_point : *testing_data)
    {
        find_k_nearest(query_point);
        double prediction = predict(false, false);
        if (prediction == query_point->get_label())
            correct++;
        data_index++;
        printf("Test sample %d: %s\n", data_index, prediction == query_point->get_label() ? "Correct" : "Incorrect");
    }
    printf("Test accuracy: %f\n", (double)correct / testing_data->size());
    return (double)correct / testing_data->size();
}
