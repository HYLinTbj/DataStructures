#ifndef LIST_HPP
#define LIST_HPP

#include "QueueBase.hpp"

template <typename T>
class List : public QueueBase<T> {
public:
	List(int);
	~List();
	T& Get(int);
	void Delete(int);
	void Insert(int, const T&);
};

#endif // !LIST_HPP
