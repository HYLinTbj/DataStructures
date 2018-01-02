#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include "MaxPriorityQueue.hpp"

template <typename T>
class MaxHeap : public MaxPriorityQueue {
public:
	MaxHeap(int);
	~MaxHeap();
private:
	T* heap_;
	int size_;
	int capacity_;
	static const int kDefaultCapacity;
};

#endif