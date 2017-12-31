#ifndef QUEUEBASE_HPP
#define QUEUEBASE_HPP

template <typename T>
class QueueBase {
public:
	QueueBase(int);
	~QueueBase();
	bool IsEmpty() const;
	int Size() const;
	int Capacity() const;
protected:
	void DoubleSpace();
	static const int kDefaultCapacity;
	T *container_;
	int front_, rear_, capacity_;
};

template <typename T> Queue<T>::kDefaultCapacity = 10;

#endif // !QUEUEBASE_HPP
