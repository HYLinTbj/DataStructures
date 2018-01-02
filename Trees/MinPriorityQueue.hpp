#ifndef MINPRIORITYQUEUE_HPP
#define MINPRIORITYQUEUE_HPP

template <typename T>
class MinPriorityQueue {
public:
	virtual ~MinPriorityQueue() {}
	virtual bool IsEmpty() const = 0;
	virtual const T& Top() const = 0;
	virtual void Push(const T&) = 0;
	virtual void Pop() = 0;
};

#endif