// heap.cpp
// Yifei Zheng

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end);
  int n = vdata.size();
  for(int i = n/2-1; i >= 0; i--) {
    heapify(i);
  }
}

void Heap::heapify(int value) {
  int n = vdata.size();
  int smallest = value;
  int left = 2*value+1;
  int right = 2*value+2;

  if(left < n && vdata[left] < vdata[smallest]) {
    smallest = left;
  }

  if(right < n && vdata[right] < vdata[smallest]) {
    smallest = right;
  }

  if(smallest != value) {
    std::swap(vdata[smallest], vdata[value]);
    heapify(smallest);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size()-1;
  int parent;
  while(i > 0) {
    parent = (i-1)/2;
    if(vdata[i] < vdata[parent]) {
      std::swap(vdata[i], vdata[parent]);
      i = parent;
    }
    else break;
  }
  
}



// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.empty()) return;
  else {
    std::swap(vdata[0], vdata[vdata.size()-1]);
    vdata.pop_back();
  }
  if(!vdata.empty()) heapify(0);
}

// Returns the minimum element in the heap
int Heap::top(){

  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.empty()) throw std::runtime_error("empty heap");
  return vdata.empty();
}
    