CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o min_heap.o
	$(CXX) main.o min_heap.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

min_heap.o: min_heap.cpp min_heap.h
	$(CXX) $(CFLAGS) min_heap.cpp

clean:
	rm -rf *.o main