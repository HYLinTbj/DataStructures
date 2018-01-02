#pragma once
#include <iostream>
#include <limits>

using namespace std;

template <typename T> class Chain;
template <typename T> class ChainIterator;

template <typename T>
class ChainNode {
	friend class Chain<T>;
public:
	ChainNode(T data = T(), ChainNode<T> *link = nullptr)
		: data_(data), link_(link) {}
private:
	T data_;
	ChainNode<T> *link_;
};

template <typename T>
class Chain {
public:
	class ChainIterator {
	public:
		ChainIterator(ChainNode<T>* start_node = nullptr)
			: current_(start_node) {}

		T& operator*() const { return current_->data_; }
		T* operator->() const { return &current_->data_; }

		ChainIterator& operator++() {
			current_ = current_->link_;
			return *this;
		}
		ChainIterator operator++(int) {
			ChainIterator old = *this;
			current_ = current_->link_;
			return old;
		}

		bool operator!=(const ChainIterator another) const {
			return current_ != another->current_;
		}
		bool operator==(const ChainIterator another) const {
			return current_ == another->current_;
		}
	private:
		ChainNode<T> *current_;
	};
	Chain();
	~Chain();
	T& Front();
	T& Back();
	T& Get(int);
	void InsertFront(const T&);
	void InsertBack(const T&);
	void InsertAt(int, const T&);
	void DeleteFront();
	void DeleteBack();
	void DeleteAt(int);
	ChainIterator begin() { return ChainIterator(first_); }
	ChainIterator end() { return ChainIterator(nullptr); }
	friend ostream& operator<<(ostream&, const Chain&);
private:
	ChainNode<T> *first_;
};