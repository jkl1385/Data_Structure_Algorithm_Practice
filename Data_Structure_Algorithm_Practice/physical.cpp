#include <iostream>
#include <iomanip>
constexpr auto VMAX = 21;
using namespace std;

struct PhysCheck {
	char name[20];
	int height;
	double vision;
};

double ave_height(const PhysCheck dat[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += dat[i].height;
	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]) {
	for (int i = 0; i < VMAX; i++) dist[i] = 0;
	for (int i = 0; i < n; i++) {
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			dist[(int)dat[i].vision * 10]++;
	}
}

int main() {
	PhysCheck x[] = {
		{ "������", 162, 0.3 },
		{ "������", 173, 0.7 },
		{ "������", 175, 2.0 },
		{ "ȫ����", 171, 1.5 },
		{ "�̼���", 168, 0.4 },
		{ "�迵��", 174, 1.2 },
		{ "�ڿ��", 169, 0.8 },
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	cout << "����� ��ü�˻�ǥ �����\n"
		<< "  �̸�          Ű      �÷�\n"
		<< "----------------------------\n";
	cout << fixed << setprecision(1);
	for (int i = 0; i < nx; i++)
		cout << x[i].name
		<< setw(12) << x[i].height
		<< setw(10) << x[i].vision << '\n';
	cout << "\n��� Ű: " << ave_height(x, nx) << " cm\n";
	dist_vision(x, nx, vdist);
	cout << "\n�÷� ����\n";
	for (int i = 0; i < VMAX; i++)
		cout << i / 10.0 << " ~ : " << vdist[i] << "��\n";

	return 0;
}