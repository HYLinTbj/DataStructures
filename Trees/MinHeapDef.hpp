#ifndef MINHEAPDEF_HPP
#define MINHEAPDEF_HPP

#include "MinHeap.hpp"
#include "Methods.hpp"

template <typename T> MinHeap<T>::kDefaultCapacity = 10;

template <typename T>
MinHeap<T>::MinHeap(int capacity = kDefaultCapacity) {
	if (capacity < 1) throw "Capacity must >= 1!";
	size_ = 0;
	capacity_ = capacity;
	heap_ = new int[capacity_ + 1];
}

template <typename T>
bool MinHeap<T>::IsEmpty() {
	return size_ == 0;
}

template <typename T>
const T& MinHeap<T>::Top() {
	return heap_[1];
}

template <typename T>
void MinHeap<T>::Push(const &T element) {
	if (size_ == capacity_) {
		ChangeSize1D(heap_, capacity_ + 1, 2 * capacity_ + 1);
		capacity_ *= 2;
	}
	int current_node = ++size_;
	while (current_node > 1 && heap[current_node / 2] < element) {
		heap_[current_node] = heap_[current_node / 2];
		current_node /= 2;
	}
	heap_[current_node] = element;
}

template <typename T>
void MinHeap<T>::Pop() {
	if (IsEmpty()) throw "Heap is empty. Cannot delete.";
	heap_[1].~T();

	T last_element = heap_[size_--];

	int current_node = 1;
	int child = 2;
	while (child <= size_) {
		if (child < size_ && heap_[child] < heap_[child + 1]) child++;
		if (last_element > heap_[child]) break;
		heap_[current_node] = heap_[child];
		current_node = child;
		child *= 2;
	}
	heap_[current_node] = last_element;
}

#endif