#include <iostream>
using namespace std;

int bin_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) return pc;
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

int main() {
	int i, nx, ky, idx;
	int* x;
	cout << "이진 검색\n";
	cout << "요소 개수: ";
	cin >> nx;
	x = new int[nx];

	cout << "오름차순으로 입력하세요.\n";
	cout << "x[0]: ";
	cin >> x[0];
	for (i = 1; i < nx; i++) {
		do {
			cout << "x[" << i << "]: ";
			cin >> x[i];
		} while (x[i] < x[i - 1]);				/* 오름차순으로 입력 */
	}

	cout << "검색값: ";
	cin >> ky;
	idx = bin_search(x, nx, ky);
	if (idx == -1) cout << "검색에 실패했습니다.\n";
	else cout << ky << "(은)는 x[" << idx << "]에 있습니다.\n";

	delete[] x;
	return 0;
}