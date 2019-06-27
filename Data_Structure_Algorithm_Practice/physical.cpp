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
		{ "박현규", 162, 0.3 },
		{ "함진아", 173, 0.7 },
		{ "최윤미", 175, 2.0 },
		{ "홍연의", 171, 1.5 },
		{ "이수진", 168, 0.4 },
		{ "김영준", 174, 1.2 },
		{ "박용규", 169, 0.8 },
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	cout << "■□■□ 신체검사표 □■□■\n"
		<< "  이름          키      시력\n"
		<< "----------------------------\n";
	cout << fixed << setprecision(1);
	for (int i = 0; i < nx; i++)
		cout << x[i].name
		<< setw(12) << x[i].height
		<< setw(10) << x[i].vision << '\n';
	cout << "\n평균 키: " << ave_height(x, nx) << " cm\n";
	dist_vision(x, nx, vdist);
	cout << "\n시력 분포\n";
	for (int i = 0; i < VMAX; i++)
		cout << i / 10.0 << " ~ : " << vdist[i] << "명\n";

	return 0;
}