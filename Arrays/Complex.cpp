#include "Complex.hpp"

Complex::Complex(double real, double imaginary)
	: real_(real), imaginary_(imaginary) {}

Complex::~Complex() {}

Complex Complex::operator+(const Complex& another) {
	return Complex(real_ + another.real_, 
		imaginary_ + another.imaginary_);
}

Complex Complex::operator*(const Complex& another) {
	return Complex(real_ * another.real_ -
		imaginary_ * another.imaginary_,
		real_ * another.imaginary_ + imaginary_ * another.real_);
}

ostream& operator<<(ostream& os, const Complex& c) {
	os << c.real_ << " + " << c.imaginary_ << "i";
	return os;
}

istream& operator>>(istream& is, Complex& c) {
	is >> c.real_ >> c.imaginary_ ;
	return is;
}

