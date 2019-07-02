#include <iostream>
using namespace std;

class IntQueue {
private:
	int max;
	int num;
	int front;
	int rear;
	int* que;
public:
	int initialize(int);
	int enque(int);
	int deque(int*);
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

int IntQueue::initialize(int max) {
	num = front = rear = 0;
	if ((que = new int[max]) == NULL) {
		this->max = 0;
		return -1;
	}
	this->max = max;
	return 0;
}

int IntQueue::enque(int x) {
	if (num >= max) return -1;
	else {
		num++;
		que[rear++] = x;
		if (rear == max) rear = 0;
		return 0;
	}
}

int IntQueue::deque(int* x) {
	if (num <= 0) return -1;
	else {
		num--;
		*x = que[front++];
		if (front == max) front = 0;
		return 0;
	}
}

int IntQueue::peek(int* x) const {
	if (num <= 0) return -1;
	*x = que[front];
	return 0;
}

void IntQueue::clear() {
	num = front = rear = 0;
}

int IntQueue::capacity() const {
	return max;
}

int IntQueue::size() const {
	return num;
}

int IntQueue::isEmpty() const {
	return num <= 0;
}

int IntQueue::isFull() const {
	return num >= max;
}

int IntQueue::search(int x) const {
	int i, idx;
	for (i = 0; i < num; i++)
		if (que[idx = (i + front) % max] == x)
			return idx;
	return -1;
}

void IntQueue::print() const {
	int i;
	for (i = 0; i < num; i++)
		cout << que[(i + front) % max] << ' ';
	cout << '\n';
}

void IntQueue::terminate() {
	if (que != NULL) delete[] que;
	max = num = front = rear = 0;
}

int main() {
	IntQueue q;
	if (q.initialize(64) == -1) {
		cout << "ť�� ������ �����Ͽ����ϴ�.\n";
		return 1;
	}

	while (1) {
		int menu, x, idx;
		cout << "\n���� ������ �� : " << q.size() << '/' << q.capacity() << '\n';
		cout << "(1) ��ť (2) ��ť (3) ��ũ (4) �˻� (5) ��� (0) ���� : ";
		cin >> menu;

		if (menu == 0) break;
		switch (menu) {
		case 1:
			cout << "������ : ";
			cin >> x;
			if (q.enque(x) == -1) cout << "\a���� : ��ť�� �����Ͽ����ϴ�.\n";
			break;

		case 2:
			if (q.deque(&x) == -1) cout << "\a���� : ��ť�� �����Ͽ����ϴ�.\n";
			else cout << "��ť �����ʹ� " << x << "�Դϴ�.\n";
			break;

		case 3:
			if (q.peek(&x) == -1) cout << "\a���� : ��ũ�� �����Ͽ����ϴ�.\n";
			else cout << "��ũ �����ʹ� " << x << "�Դϴ�.\n";
			break;

		case 4:
			cout << "������ : ";
			cin >> x;
			if ((idx = q.search(x)) == -1) cout << "\a���� : �˻��� �����Ͽ����ϴ�.\n";
			else cout << "������ " << x << "(��)�� " << idx << "��°�� �ֽ��ϴ�.\n";
			break;

		case 5:
			q.print();
			break;
		}
	}

	q.terminate();
	return 0;
}