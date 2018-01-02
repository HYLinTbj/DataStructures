#include "Stack.hpp"

template <typename T> Stack<T>::kDefaultCapacity = 20;

template <typename T>
Stack<T>::Stack(int capacity = kDefaultCapacity)
	: capacity_(capacity) {
	if (capacity_ < 1) throw "Capacity must be larger than 0";
	container_ = new T[capacity_];
	top_ = 0;
}

template <typename T>
Stack<T>::~Stack() {
	delete[] container_;
}

template <typename T>
inline bool Stack<T>::IsEmpty() const {
	return top_ == 0;
}

template <typename T>
inline int Stack<T>::Size() const {
	return top_;
}

template <typename T>
inline int Stack<T>::Capacity() const {
	return capacity_;
}

template <typename T>
T& Stack<T>::Top() const {
	if (IsEmpty()) throw "Stack is empty!";
	return container_[top_ - 1];
}

template <typename T>
void Stack<T>::Push(const T& element) {
	if (top_ == capacity_) DoubleSpace();
	container_[top_++] = element;
}

template <typename T>
void Stack<T>::Pop() {
	if (IsEmpty()) throw "Stack is empty!";
	container_[--top_].~T();
}

template <typename T>
void Stack<T>::DoubleSpace() {
	T *bigger_container = new T[2 * capacity_];
	for (int i = 0; i < capacity_; i++)
		bigger_container[i] = container_[i];
	capacity_ *= 2;
	delete[] container_;
	container_ = bigger_container;
}