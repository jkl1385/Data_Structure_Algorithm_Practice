#include <iostream>
using namespace std;

void move(int no, int x, int y) {
	if (no > 1) move(no - 1, x, 6 - x - y);
	cout << "����[" << no << "]��(��) " << x << " ��տ��� " << y << " ������� �ű�\n";
	if (no > 1) move(no - 1, 6 - x - y, y);
}

int main() {
	int n;
	cout << "�ϳ����� ž\n���� ���� : ";
	cin >> n;
	move(n, 1, 3);

	return 0;
}