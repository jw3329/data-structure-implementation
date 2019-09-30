CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o tree_node.o binary_search_tree.o
	$(CXX) main.o tree_node.o binary_search_tree.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

tree_node.o: tree_node.cpp tree_node.h
	$(CXX) $(CFLAGS) tree_node.cpp

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
	$(CXX) $(CFLAGS) binary_search_tree.cpp

clean:
	rm -r *.o main