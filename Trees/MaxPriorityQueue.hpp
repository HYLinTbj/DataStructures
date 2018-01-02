#ifndef MAXPRIORITYQUEUE_HPP
#define MAXPRIORITYQUEUE_HPP

template <typename T>
class MaxPriorityQueue {
public:
	virtual ~MaxPriorityQueue() {}
	virtual bool IsEmpty() const = 0;
	virtual const T& Top() const = 0;
	virtual void Push(const T&) = 0;
	virtual void PushEX(const T&) = 0;
	virtual void Pop() = 0;
	virtual void PopEX() = 0;
};

#endif