#include <iostream>
using namespace std;

class IntStack {
private:
	int max;
	int ptr;
	int* stk;
public:
	int initialize(int);
	int push(int);
	int pop(int*);
	int peek(int*) const;
	void clear();
	int capacity() const;
	int size() const;
	int isEmpty() const;
	int isFull() const;
	int search(int) const;
	void print() const;
	void terminate();
};

int IntStack::initialize(int max) {
	ptr = 0;
	if ((stk = new int[max]) == NULL) {
		this->max = 0;
		return -1;
	}
	this->max = max;
	return 0;
}

int IntStack::push(int x) {
	if (ptr >= max) return -1;
	stk[ptr++] = x;
	return 0;
}

int IntStack::pop(int* x) {
	if (ptr <= 0) return -1;
	*x = stk[--ptr];
	return 0;
}

int IntStack::peek(int* x) const {
	if (ptr <= 0) return -1;
	*x = stk[ptr - 1];
	return 0;
}

void IntStack::clear() {
	ptr = 0;
}

int IntStack::capacity() const {
	return max;
}

int IntStack::size() const {
	return ptr;
}

int IntStack::isEmpty() const {
	return ptr <= 0;
}

int IntStack::isFull() const {
	return ptr >= max;
}

int IntStack::search(int x) const {
	for (int i = ptr - 1; i >= 0; i--)
		if (stk[i] == x)
			return i;
	return -1;
}

void IntStack::print() const {
	for (int i = 0; i < ptr; i++)
		cout << stk[i] << ' ';
	cout << '\n';
}

void IntStack::terminate() {
	if (stk != NULL) delete[] stk;
	max = ptr = 0;
}

int main() {
	IntStack s;
	if (s.initialize(64) == -1) {
		cout << "스택 생성에 실패하였습니다.\n";
		return 1;
	}

	while (1) {
		int menu, x, idx;
		cout << "\n현재 데이터 수 : " << s.size() << '/' << s.capacity() << '\n';
		cout << "(1) 푸시 (2) 팝 (3) 피크 (4) 검색 (5) 출력 (0) 종료 : ";
		cin >> menu;

		if (menu == 0) break;
		switch (menu) {
		case 1:
			cout << "데이터 : ";
			cin >> x;
			if (s.push(x) == -1) cout << "\a오류 : 푸시에 실패하였습니다.\n";
			break;

		case 2:
			if (s.pop(&x) == -1) cout << "\a오류 : 팝에 실패하였습니다.\n";
			else cout << "팝 데이터는 " << x << "입니다.\n";
			break;

		case 3:
			if (s.peek(&x) == -1) cout << "\a오류 : 피크에 실패하였습니다.\n";
			else cout << "피크 데이터는 " << x << "입니다.\n";
			break;

		case 4:
			cout << "데이터 : ";
			cin >> x;
			idx = s.search(x);
			if (idx == -1) cout << "\a오류 : 검색에 실패하였습니다.\n";
			else cout << "데이터 " << x << "(은)는 " << idx << "번째에 있습니다.\n";
			break;

		case 5:
			s.print();
			break;
		}
	}

	s.terminate();
	return 0;
}