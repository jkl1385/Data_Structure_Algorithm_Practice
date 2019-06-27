#include <iostream>
using namespace std;

int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else {
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
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