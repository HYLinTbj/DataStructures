#include "Queue.hpp"

template <typename T>
Queue<T>::Queue(int capacity = kDefaultCapacity)
	: QueueBase(capacity) {}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
T& Queue<T>::Front() const {
	if (IsEmpty()) throw "Queue is empty!";
	return container_[(front_ + 1) % capacity_];
}

template <typename T>
T& Queue<T>::Rear() const {
	if (IsEmpty()) throw "Queue is empty!";
	return container_[rear_];
}

template <typename T>
void Queue<T>::Push(const T& element) {
	if (rear_ + 1 == front_) {
		DoubleSpace();
	}
	rear_ = (rear_ + 1) % capacity_;
	container_[rear_] = element;
}

template <typename T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty!";
	front_ = (front_ + 1) % capacity_;
	container_[front_].~T();
}