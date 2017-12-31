#include "QueueBase.hpp"

template <typename T>
QueueBase<T>::QueueBase(int capacity = kDefaultCapacity)
	: capacity_(capacity) {
	if (capacity_ < 1) throw "Capacity must be larger than 0";
	container_ = new T[capacity_];
	front_ = rear_ = 0;
}

template <typename T>
QueueBase<T>::~QueueBase() {
	delete[] container_;
}

template <typename T>
inline bool QueueBase<T>::IsEmpty() const {
	return front_ == rear_;
}

template <typename T>
inline int QueueBase<T>::Size() const {
	return (rear_ - front_ + capacity_) % capacity_;
}

template <typename T>
inline int QueueBase<T>::Capacity() const {
	return capacity_;
}


template <typename T>
void QueueBase<T>::DoubleSpace() {
	T *bigger_container = new T[2 * capacity_];
	for (int i = 0; i < capacity_ - 1; i++)
		bigger_container[i] = container_[(front_ + i + 1) % capacity_];

	front_ = 2 * capacity_ - 1;
	rear_ = capacity_ - 2;
	capacity_ *= 2;
	delete[] container_;
	container_ = bigger_container;
}