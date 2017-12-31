#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "Queue.hpp"

template <typename T>
class Deque : public Queue<T> {
public:
	Deque(int);
	~Deque();
	void PushFront(const T&);
	void PopFront();
	void PushRear(const T&);
	void PopRear();
private:
	// Since we already have PushRear() and PopFront(),
	// we don't want these two accessible outside the class.
	using Queue<T>::Push;
	using Queue<T>::Pop;
};

#endif