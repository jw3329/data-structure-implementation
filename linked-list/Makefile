CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o node.o linked_list.o
	$(CXX) main.o node.o linked_list.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

linked_list.o: linked_list.cpp linked_list.h
	$(CXX) $(CFLAGS) linked_list.cpp

node.o: node.cpp node.h
	$(CXX) $(CFLAGS) node.cpp

clean:
	rm -r *.o main