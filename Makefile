CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: examheap

examheap: examheap.o heap.o
	g++ -std=c++17 -Wall -Wextra examheap.o heap.o -o examheap

examheap.o: examheap.cpp heap.h
	g++ -std=c++17 -Wall -Wextra -c examheap.cpp

heap.o: heap.cpp heap.h
	g++ -std=c++17 -Wall -Wextra -c heap.cpp

clean:
	rm -f *.o examheap