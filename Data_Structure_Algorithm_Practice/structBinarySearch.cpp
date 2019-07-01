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
		{ "김영준", 179, 79 },
		{ "박현규", 172, 63 },
		{ "이수진", 176, 52 },
		{ "최윤미", 165, 51 },
		{ "함진아", 181, 73 },
		{ "홍연의", 172, 84 },
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	cout << "이름으로 검색합니다.\n";
	do {
		Person temp, * p;
		cout << "이름: ";
		cin >> temp.name;
		p = (Person*)bsearch(&temp, x, nx, sizeof(Person),
			[](const void* x, const void* y) {
				return strcmp(((Person*)x)->name, ((Person*)y)->name);
			});
		if (p == NULL) cout << "검색에 실패했습니다.\n";
		else {
			cout << "검색 성공!! 아래 요소를 찾았습니다.\n";
			cout << "x[" << (int)(p - x) << "]: " << p->name << " " << p->height << "cm " << p->weight << "kg\n";
		}
		cout << "다시 검색할까요?(1) 예 /(0) 아니오: ";
		cin >> retry;
	} while (retry == 1);

	return 0;
}