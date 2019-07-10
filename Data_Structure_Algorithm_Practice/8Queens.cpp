#include <iostream>
#include <iomanip>
using namespace std;

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print() {
	for (int i = 0; i < 8; i++)
		cout << setw(2) << pos[i];
	cout << '\n';
}

void print2() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << (pos[i] == j ? "бс" : "бр");
		cout << '\n';
	}
	cout << '\n';
}

void set(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7) print2();
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main() {
	set(0);

	return 0;
}