#include "Deque.hpp"

template <typename T>
Deque<T>::Deque(int capacity = kDefaultCapacity)
	: QueueBase(capacity) {}

template <typename T>
Deque<T>::~Deque() {}

template <typename T>
void Deque<T>::PushFront(const T& element) {
	if (front_ - 1 == rear_) {
		DoubleSpace();
	}
	container_[front_] = element;
	front_ = (front_ - 1) % capacity_;
}

template <typename T>
void Deque<T>::PopFront() {
	Pop();
}

template <typename T>
void Deque<T>::PushRear(const T& element) {
	Push(element);
}

template <typename T>
void Deque<T>::PopRear() {
	if (isEmpty()) throw "Queue Empty!";
	container_[rear_].~T();
	rear = (rear - 1) % capacity_;	
}