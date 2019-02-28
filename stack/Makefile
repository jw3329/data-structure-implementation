CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o
	$(CXX) main.o -o main

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

clean:
	rm -r *.o main