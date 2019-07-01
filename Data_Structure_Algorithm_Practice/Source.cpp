#include <iostream>
using namespace std;

int search(const int a[], int n, int key) {
	int i = 0;
	a[n] = key;
	while (1) {
		if (a[i] == key) break;
		i++;
	}
	return i == n ? -1 : i;
}

int main() {
	int i, nx, ky, idx;
	int* x;
	cout << "���� �˻�\n";
	cout << "��� ����: ";
	cin >> nx;
	x = new int[nx + 1];
	for (i = 0; i < nx; i++) {
		cout << "x[" << i << "]: ";
		cin >> x[i];
	}

	cout << "�˻���: ";
	cin >> ky;
	idx = search(x, nx, ky);
	if (idx == -1)
		cout << "�˻��� �����߽��ϴ�.\n";
	else
		cout << ky << "(��)�� x[" << idx << "]�� �ֽ��ϴ�.\n";

	delete[] x;
	return 0;
}