CC=clang++
INCLUDE_DIR = $(MNIST_ROOT)/include
SRC_DIR = $(MNIST_ROOT)/src
LIB_DATA = libdata.so
CFLAGS = -std=c++11 -g

all: $(LIB_DATA)

$(LIB_DATA): libdir objdir obj/data_handler.o obj/data.o
	$(CC) $(CFLAGS) -o $(MNIST_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(MNIST_ROOT)/obj

libdir:
	mkdir -p $(MNIST_ROOT)/lib

objdir:
	mkdir -p $(MNIST_ROOT)/obj

obj/data_handler.o: $(SRC_DIR)/data_handler.cc $(INCLUDE_DIR)/data_handler.hpp
	$(CC) -fPIC $(CFLAGS) -o obj/data_handler.o -I$(INCLUDE_DIR) -c $(SRC_DIR)/data_handler.cc

obj/data.o: $(SRC_DIR)/data.cc $(INCLUDE_DIR)/data.hpp
	$(CC) -fPIC $(CFLAGS) -o obj/data.o -I$(INCLUDE_DIR) -c $(SRC_DIR)/data.cc

clean:
	rm -rf lib obj

