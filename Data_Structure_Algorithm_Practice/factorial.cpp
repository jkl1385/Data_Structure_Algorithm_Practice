#include <iostream>
using namespace std;

int factorial(int n) {
	if (n > 0) return n * factorial(n - 1);
	else return 1;
}

int main() {
	int x;
	cout << "정수를 입력하세요 : ";
	cin >> x;
	cout << x << "! = " << factorial(x) << '\n';

	return 0;
}