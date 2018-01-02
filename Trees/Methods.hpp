#ifndef METHODS_HPP
#define METHODS_HPP

template <typename T>
void ChangeSize1D(T*& a, const int old_capacity, const int new_capacity) {
	if (new_capacity < 1) throw "Capacity must >= 1!";

	T *temp = new T[new_capacity];
	int size = old_capacity < new_capacity ? old_capacity : new_capacity;
	for (int i = 0; i < size; i++)
		temp[i] = a[i];
	delete[]a;
	a = temp;
}

#endif