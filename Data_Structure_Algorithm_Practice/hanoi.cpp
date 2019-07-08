#include <iostream>
using namespace std;

void move(int no, int x, int y) {
	if (no > 1) move(no - 1, x, 6 - x - y);
	cout << "원반[" << no << "]를(을) " << x << " 기둥에서 " << y << " 기둥으로 옮김\n";
	if (no > 1) move(no - 1, 6 - x - y, y);
}

int main() {
	int n;
	cout << "하노이의 탑\n원반 개수 : ";
	cin >> n;
	move(n, 1, 3);

	return 0;
}