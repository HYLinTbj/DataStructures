#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include "MinPriorityQueue.hpp"

template <typename T>
class MinHeap : public MinPriorityQueue<T> {
public:
	MinHeap(int);
private:
	T* heap_;
	int size_;
	int capacity_;
	static const int kDefaultCapacity;
};

#endif