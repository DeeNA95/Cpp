# MNIST Data Handler

This is a C++ library for handling MNIST data.
Made following [this tutorial](https://youtu.be/E1K9SZCm0fQ) by [Gerard Taylor](https://www.youtube.com/@gerardonfiya)

## Installation

1. Clone the repository
2. Run `make` to build the library
3. Run `make clean` to clean up the build files

## Usage

1. Include the library in your project
2. Use the `DataHandler` class to read and write MNIST data

Data downloaded from [Google Cloud Storage](https://storage.googleapis.com/cvdf-datasets/mnist/)

``` bash
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
