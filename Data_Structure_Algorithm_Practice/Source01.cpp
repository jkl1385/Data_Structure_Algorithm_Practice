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
	cout << "��� �� �Է�: ";
	cin >> N;

	int* height = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "height[" << i << "]: ";
		cin >> height[i];
	}

	cout << "�ִ��� " << maxHeight(height, N) << "�Դϴ�.\n";

	delete[] height;
	return 0;
}