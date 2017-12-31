#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueBase.hpp"

template <typename T>
class Queue : public QueueBase<T>{
public:
	Queue(int);
	~Queue();
	T& Front() const;
	T& Rear() const;
	void Push(const T&);
	void Pop();
};

#endif