CXX = g++

CFLAGS = -std=c++11 -c -Wall

all: build

build: main.o
	$(CXX) main.o -o main

main.o: main.cpp hash_map.h hash_node.h key_hash.h
	$(CXX) $(CFLAGS) main.cpp

clean:
	rm -r *.o main