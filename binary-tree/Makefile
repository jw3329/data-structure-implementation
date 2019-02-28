CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o tree_node.o binary_tree.o
	$(CXX) main.o tree_node.o binary_tree.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

tree_node.o: tree_node.cpp tree_node.h
	$(CXX) $(CFLAGS) tree_node.cpp

binary_tree.o: binary_tree.cpp binary_tree.h
	$(CXX) $(CFLAGS) binary_tree.cpp

clean:
	rm -r *.o main