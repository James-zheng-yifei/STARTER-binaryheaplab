CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) examheap.o heap.o -o examheap

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
	rm -f *.o examheap