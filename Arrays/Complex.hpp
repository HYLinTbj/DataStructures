#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
using namespace std;

class Complex {
public:
	Complex(double, double);
	~Complex();
	Complex operator+(const Complex&);
	Complex operator*(const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
private:
	double real_, imaginary_;
};

#endif