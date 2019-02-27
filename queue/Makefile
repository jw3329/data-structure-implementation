CXX = g++

CFLAGS = -c -Wall

all: build

build: main.o queue.o
	$(CXX) main.o queue.o -o queue

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

queue.o: queue.cpp
	$(CXX) $(CFLAGS) queue.cpp

clean:
	rm -r *.o queue