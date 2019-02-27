CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o stack.o
	$(CXX) main.o stack.o -o stack

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

stack.o: stack.cpp stack.h
	$(CXX) $(CFLAGS) stack.cpp

clean:
	rm -r *.o stack