#include <iostream>
#include <cstring>
using namespace std;

struct Person {
	char name[10];
	int height;
	int weight;
};

int main() {
	Person x[] = {
		{ "�迵��", 179, 79 },
		{ "������", 172, 63 },
		{ "�̼���", 176, 52 },
		{ "������", 165, 51 },
		{ "������", 181, 73 },
		{ "ȫ����", 172, 84 },
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	cout << "�̸����� �˻��մϴ�.\n";
	do {
		Person temp, * p;
		cout << "�̸�: ";
		cin >> temp.name;
		p = (Person*)bsearch(&temp, x, nx, sizeof(Person),
			[](const void* x, const void* y) {
				return strcmp(((Person*)x)->name, ((Person*)y)->name);
			});
		if (p == NULL) cout << "�˻��� �����߽��ϴ�.\n";
		else {
			cout << "�˻� ����!! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.\n";
			cout << "x[" << (int)(p - x) << "]: " << p->name << " " << p->height << "cm " << p->weight << "kg\n";
		}
		cout << "�ٽ� �˻��ұ��?(1) �� /(0) �ƴϿ�: ";
		cin >> retry;
	} while (retry == 1);

	return 0;
}