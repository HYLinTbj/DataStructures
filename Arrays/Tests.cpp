#include "Complex.hpp"

void ComplexTest();

int main() {
	system("pause");
}

void ComplexTest() {
	Complex c1(2, 5), c2(3, 2);
	cout << "c1 * c2 = " << c1 * c2 << endl;
	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "Reset c1:";
	cin >> c1;
	cout << "c1 * c2 = " << c1 * c2 << endl;
	cout << "c1 + c2 = " << c1 + c2 << endl;
}