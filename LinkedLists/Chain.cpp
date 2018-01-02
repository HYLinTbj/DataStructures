#include "Chain.hpp"

template <typename T>
Chain<T>::Chain()
	: first_(nullptr) {}

template <typename T>
Chain<T>::~Chain() {
	ChainNode<T>* next;
	for (; first_; first_ = next) {
		next = first_->next;
		delete first_;
	}
}

template <typename T>
T& Chain<T>::Front() {
	return first_ ? first_->data_ : T();
}

template <typename T>
T& Chain<T>::Back() {
	
}

template <typename T>
ostream& operator<<(ostream& os, const Chain<T>& c) {
	for (ChainIterator<T> it = c.begin(); it != c.end(); it++)
		os << *it << ' ';
	return os;
}

template <typename T>
void Chain<T>::InsertFront(const T& element) {
	if (!first_)
		first_ = new ChainNode<T>(element);
	else
		first_ = new ChainNode<T>(element, first_);
}

template <typename T>
void Chain<T>::InsertBack(const T& element) {
	if (!first_)
		first_ = new ChainNode<T>(element);
	else {
		ChainNode<T>* ptr;
		for (ptr = first_; ptr->link_; ptr = ptr->link_);
		ptr->link_ = new ChainNode<T>(element);
	}
}

template <typename T>
void Chain<T>::DeleteFront() {
	if (!first_)
		return;
	ChainNode<T>* temp = first_;
	first_ = first_->link_;
	delete temp;
}

template <typename T>
void Chain<T>::DeleteBack() {
	if (!first_)
		return;
	ChainNode<T>* ptr;
	for (ptr = first_; ptr->link_; ptr = ptr->link_);
	delete ptr;
}