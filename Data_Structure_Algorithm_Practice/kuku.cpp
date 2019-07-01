#include <iostream>
using namespace std;

int sum(int x1, int x2) {
	return x1 + x2;
}

int mul(int x1, int x2) {
	return x1 * x2;
}

void kuku(int(*calc)(int, int)) {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++)
			printf("%3d", (*calc)(i, j));
		cout << '\n';
	}
}

int main() {
	cout << "µ¡¼ÀÇ¥\n";
	kuku(sum);
	cout << "\n°ö¼ÀÇ¥\n";
	kuku(mul);

	return 0;
}