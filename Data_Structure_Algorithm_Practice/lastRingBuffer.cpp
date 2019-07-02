#include <iostream>
constexpr auto N = 10;
using namespace std;

int main() {
	int i;
	int a[N];				/* 입력한 데이터를 저장 */
	int cnt = 0;			/* 입력한 데이터의 개수 */
	int retry;				/* 다시 한 번? */
	cout << "정수를 입력하세요.\n";
	do {
		cout << cnt + 1 << "번째 정수 : ";
		cin >> a[cnt++ % N];
		cout << "계속할까요?(Y:1/N:0) : ";
		cin >> retry;
	} while (retry == 1);

	i = cnt - N;
	if (i < 0) i = 0;
	for (; i < cnt; i++)
		cout << i + 1 << "번째 정수 = " << a[i % N] << '\n';

	return 0;
}