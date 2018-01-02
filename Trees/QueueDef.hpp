#include "Queue.hpp"

template <typename T> Queue<T>::kDefaultCapacity = 20;

template <typename T>
Queue<T>::Queue(int capacity = kDefaultCapacity)
	: capacity_(capacity) {
	if (capacity_ < 1) throw "Capacity must be larger than 0";
	container_ = new T[capacity_];
	front_ = rear_ = 0;
}

template <typename T>
Queue<T>::~Queue() {
	delete[] container_;
}

template <typename T>
inline bool Queue<T>::IsEmpty() const {
	return front_ == rear_;
}

template <typename T>
inline int Queue<T>::Size() const {
	return (rear_ - front_ + capacity_) % capacity_;
}

template <typename T>
inline int Queue<T>::Capacity() const {
	return capacity_;
}

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

template <typename T>
void Queue<T>::DoubleSpace() {
	T *bigger_container = new T[2 * capacity_];
	for (int i = 0; i < capacity_ - 1; i++)
		bigger_container[i] = container_[(front_ + i + 1) % capacity_];

	front_ = 2 * capacity_ - 1;
	rear_ = capacity_ - 2;
	capacity_ *= 2;
	delete[] container_;
	container_ = bigger_container;
}