#include <iostream>
constexpr auto N = 10;
using namespace std;

int main() {
	int i;
	int a[N];				/* �Է��� �����͸� ���� */
	int cnt = 0;			/* �Է��� �������� ���� */
	int retry;				/* �ٽ� �� ��? */
	cout << "������ �Է��ϼ���.\n";
	do {
		cout << cnt + 1 << "��° ���� : ";
		cin >> a[cnt++ % N];
		cout << "����ұ��?(Y:1/N:0) : ";
		cin >> retry;
	} while (retry == 1);

	i = cnt - N;
	if (i < 0) i = 0;
	for (; i < cnt; i++)
		cout << i + 1 << "��° ���� = " << a[i % N] << '\n';

	return 0;
}