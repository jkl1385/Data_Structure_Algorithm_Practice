#include <iostream>
#include <iomanip>
using namespace std;

//p75_Q6

int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else {
		while (x) {
			cout << " " << setw(2) << n << " |" << setw(10) << x << " ������ " << dchar[x % n]
				<< "\n    + -----------\n";
			d[digits++] = dchar[x % n];
			x /= n;
		}
		cout << setw(15) << 0 << "\n\n";
	}
	return digits;
}

int main() {
	int cd, dno, retry;
	unsigned no;
	char cno[512];
	cout << "10������ ��� ��ȯ�մϴ�.\n";

	do {
		cout << "��ȯ�ϴ� ���� �ƴ� ����: ";
		cin >> no;
		do {
			cout << "� ������ ��ȯ�ұ��?(2-36): ";
			cin >> cd;
		} while (cd < 2 || cd > 36);
		cout << "\n";
		dno = card_convr(no, cd, cno);
		cout << cd << "�����δ� ";
		for (int i = dno - 1; i >= 0; i--)
			cout << cno[i];
		cout << "�Դϴ�.\n";
		cout << "�� �� �� �ұ��?(0/1): ";
		cin >> retry;
	} while (retry == 1);

	return 0;
}