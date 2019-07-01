#include <iostream>
#include <cstdlib>
using namespace std;

int int_cmp(const int* a, const int* b) {
	return *a < *b ? -1 : *a > * b ? 1 : 0;
}

int main() {
	int i, nx, ky;
	int* x, * p;
	cout << "bsearch 함수를 사용하여 검색\n";
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
	p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if (p == NULL) cout << "검색에 실패했습니다.\n";
	else cout << ky << "(은)는 x[" << (int)(p - x) << "]에 있습니다.\n";

	delete[] x;
	return 0;
}