# MNIST Data Handler

This is a C++ library for handling MNIST data.
Made following [this tutorial](https://youtu.be/E1K9SZCm0fQ) by [Gerard Taylor](https://www.youtube.com/@gerardonfiya)

## Installation

1. Clone the repository
2. Run `make` to build the library
3. Run `make clean` to clean up the build files
4. Run `make` in knn directory to build KNN classifier

## Usage

1. Include the library in your project
2. Use the `DataHandler` class to read and write MNIST data
3. Use the `KNN` class for digit classification with:
   - Configurable K value
   - Weighted/unweighted predictions
   - Built-in performance validation

## KNN Implementation

A K-Nearest Neighbors classifier implementation for MNIST digit recognition.

### Features
- Configurable K value
- Multiple distance metrics (Euclidean, Manhattan, Minkowski, (Hamming implementation planned))
- Performance logging with timing measurements
- ~97% accuracy on MNIST dataset

### Project Structure
```
ml/mnist-ml/
├── knn/
│   ├── include/
│   │   └── knn.hpp
│   ├── src/
│   │   ├── knn.cpp
│   │   └── test_knn.cpp
│   └── Makefile
├── include/
│   ├── data.hpp
│   └── data_handler.hpp
|── src/
|   ├── data.cc
|   └── data_handler.cc
|── Makefile
```

### Build and Run
```bash
cd knn
make
./test_knn
```

### Performance Metrics
Performance metrics are stored in `performance_log.csv` with the following format:
- timestamp: When the test was run
- k_value: Number of neighbors used
- distance_metric: Type of distance calculation
- training_size: Number of training samples
- test_size: Number of test samples
- validation_size: Number of validation samples
- validation_accuracy: Accuracy on validation set
- validation_time_ms: Time taken for validation
- test_accuracy: Accuracy on test set
- test_time_ms: Time taken for testing

### Future Improvements
- OpenMP parallelization for:
  - Distance calculations
  - K-nearest neighbor search
  - Validation/test predictions
- K-d tree implementation for faster neighbor search
- GPU acceleration(tentative)

Data downloaded from [Google Cloud Storage](https://storage.googleapis.com/cvdf-datasets/mnist/)

```bash
# Training images
curl -O https://storage.googleapis.com/cvdf-datasets/mnist/train-images-idx3-ubyte.gz

# Training labels
curl -O https://storage.googleapis.com/cvdf-datasets/mnist/train-labels-idx1-ubyte.gz

# Test images
curl -O https://storage.googleapis.com/cvdf-datasets/mnist/t10k-images-idx3-ubyte.gz

# Test labels
curl -O https://storage.googleapis.com/cvdf-datasets/mnist/t10k-labels-idx1-ubyte.gz

# Unzip the files
gunzip *.gz
```
