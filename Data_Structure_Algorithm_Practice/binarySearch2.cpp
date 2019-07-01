#include <iostream>
#include <cstdlib>
using namespace std;

int int_cmp(const int* a, const int* b) {
	return *a < *b ? -1 : *a > * b ? 1 : 0;
}

int main() {
	int i, nx, ky;
	int* x, * p;
	cout << "bsearch �Լ��� ����Ͽ� �˻�\n";
	cout << "��� ����: ";
	cin >> nx;
	x = new int[nx];

	cout << "������������ �Է��ϼ���.\n";
	cout << "x[0]: ";
	cin >> x[0];
	for (i = 1; i < nx; i++) {
		do {
			cout << "x[" << i << "]: ";
			cin >> x[i];
		} while (x[i] < x[i - 1]);				/* ������������ �Է� */
	}

	cout << "�˻���: ";
	cin >> ky;
	p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if (p == NULL) cout << "�˻��� �����߽��ϴ�.\n";
	else cout << ky << "(��)�� x[" << (int)(p - x) << "]�� �ֽ��ϴ�.\n";

	delete[] x;
	return 0;
}