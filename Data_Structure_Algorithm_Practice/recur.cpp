#include <iostream>
using namespace std;

void recur(int n) {
	if (n > 0) {
		recur(n - 1);
		cout << n << '\n';
		recur(n - 2);
	}
}

int main() {
	int x;
	cout << "������ �Է��ϼ��� : ";
	cin >> x;
	recur(x);

	return 0;
}