#include "knn.hpp"
#include "data_handler.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>

int main()
{
    // Create or open performance log
    std::ofstream perf_log("performance_log.csv", std::ios::app);
    if (!perf_log.is_open())
    {
        std::cerr << "Failed to open performance log file" << std::endl;
        return 1;
    }

    // Write headers if file is empty
    perf_log.seekp(0, std::ios::end);
    if (perf_log.tellp() == 0)
    {
        perf_log << "timestamp,k_value,distance_metric,training_size,test_size,validation_size,validation_accuracy,validation_time_ms,test_accuracy,test_time_ms\n";
    }

    data_handler *dh = new data_handler();
    dh->read_feature_vector("../mnist_data/train-images-idx3-ubyte");
    dh->read_feature_labels("../mnist_data/train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();

    knn *classifier = new knn(3); // k=3
    classifier->set_training_data(dh->get_training_data());
    classifier->set_test_data(dh->get_testing_data());
    classifier->set_validation_data(dh->get_validation_data());

    std::cout << "Training samples: " << dh->get_training_data()->size() << std::endl;
    std::cout << "Test samples: " << dh->get_testing_data()->size() << std::endl;
    std::cout << "Validation samples: " << dh->get_validation_data()->size() << std::endl;

    std::cout << "\nValidating model..." << std::endl;
    auto start_validation = std::chrono::high_resolution_clock::now();
    double validation_accuracy = classifier->validate_performance();
    auto end_validation = std::chrono::high_resolution_clock::now();
    auto validation_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_validation - start_validation).count();
    std::cout << "Validation accuracy: " << validation_accuracy * 100 << "%" << std::endl;
    std::cout << "Validation time: " << validation_time << "ms" << std::endl;

    std::cout << "\nTesting model..." << std::endl;
    auto start_test = std::chrono::high_resolution_clock::now();
    double test_accuracy = classifier->test_performance();
    auto end_test = std::chrono::high_resolution_clock::now();
    auto test_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_test - start_test).count();
    std::cout << "Test accuracy: " << test_accuracy * 100 << "%" << std::endl;
    std::cout << "Test time: " << test_time << "ms" << std::endl;

    // Get current timestamp
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);

    // Log performance metrics
    perf_log << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << ","
             << 3 << "," // k value
             << "euclidean" << ","
             << dh->get_training_data()->size() << ","
             << dh->get_testing_data()->size() << ","
             << dh->get_validation_data()->size() << ","
             << validation_accuracy << ","
             << validation_time << ","
             << test_accuracy << ","
             << test_time << "\n";

    perf_log.close();
    delete classifier;
    delete dh;
    return 0;
}
