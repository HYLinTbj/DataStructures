#include "List.hpp"

template <typename T>
List<T>::List(int capacity = kDefaultCapacity)
	: QueueBase(capacity) {}

template <typename T>
List<T>::~List() {}

template <typename T>
T& List<T>::Get(int index = 0) {
	if (index < 1 || index > Size())
		throw "Index out of bound!";
	return container_[(front_ + index) % capacity_];
}

template <typename T>
void List<T>::Delete(int index = 0) {

}

template <typename T>
void List<T>::Insert(int index = 0, const T& element) {

}
