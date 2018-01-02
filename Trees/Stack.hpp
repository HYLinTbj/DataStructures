#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {
public:
	Stack(int);
	~Stack();
	bool IsEmpty() const;
	int Size() const;
	int Capacity() const;
	T& Top() const;
	void Push(const T&);
	void Pop();
private:
	void DoubleSpace();
	static const int kDefaultCapacity;
	T *container_;
	int top_, capacity_;
};

#endif