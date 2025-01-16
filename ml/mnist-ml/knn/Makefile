CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./include -I../include -DEUCLIDEAN
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/knn.cpp $(SRC_DIR)/test_knn.cpp ../src/data.cc ../src/data_handler.cc
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJS := $(OBJS:../src/%.cc=$(OBJ_DIR)/%.o)

# Main target
TARGET = test_knn

all: $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ../src/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean