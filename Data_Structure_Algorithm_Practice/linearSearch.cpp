#include <iostream>
using namespace std;

int search(const int a[], int n, int key) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key) return i;
	return -1;
}

int main() {
	int i, nx, ky, idx;
	int* x;
	cout << "선형 검색\n";
	cout << "요소 개수: ";
	cin >> nx;
	x = new int[nx];
	for (i = 0; i < nx; i++) {
		cout << "x[" << i << "]: ";
		cin >> x[i];
	}

	cout << "검색값: ";
	cin >> ky;
	idx = search(x, nx, ky);
	if (idx == -1)
		cout << "검색에 실패했습니다.\n";
	else
		cout << ky << "(은)는 x[" << idx << "]에 있습니다.\n";

	delete[] x;
	return 0;
}