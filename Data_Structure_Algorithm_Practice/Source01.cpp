#include <iostream>
using namespace std;

int maxHeight(const int* a, int n) {
	int max = a[0];
	for (int i = 1; i < n; i++)
		max = max < a[i] ? a[i] : max;
	return max;
}

int main() {
	int N;
	cout << "사람 수 입력: ";
	cin >> N;

	int* height = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "height[" << i << "]: ";
		cin >> height[i];
	}

	cout << "최댓값은 " << maxHeight(height, N) << "입니다.\n";

	delete[] height;
	return 0;
}