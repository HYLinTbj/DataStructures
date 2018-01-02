#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
public:
	Queue(int);
	~Queue();
	bool IsEmpty() const;
	int Size() const;
	int Capacity() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T&);
	void Pop();
private:
	void DoubleSpace();
	static const int kDefaultCapacity;
	T *container_;
	int front_, rear_, capacity_;
};

#endif