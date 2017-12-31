#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue<int> qq(10);
	for (int i = 0; i < 9; i++)
		qq.Push(i);
	qq.Pop();
	for (int i = 0; i < 9; i++)
		qq.Push(i);
	for (int i = 0; i < 17; i++) {
		cout << qq.Front() << ' ';
		qq.Pop();
	}
	system("pause");
}