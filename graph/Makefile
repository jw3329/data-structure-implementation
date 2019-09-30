CXX = g++

CFLAGS = -c -Wall

all: build

build: vertex.o graph.o main.o
	$(CXX) vertex.o graph.o main.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

graph.o: graph.h graph.cpp
	$(CXX) $(CFLAGS) graph.cpp

vertex.o: vertex.h vertex.cpp
	$(CXX) $(CFLAGS) vertex.cpp

clean:
	rm -r *.o main