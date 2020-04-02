#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

int max = 20000;
vector<int> y(max,0);
vector<vector<int>> A(max,vector<int>(max,13));
vector<int> x(max,16);

void alg1(int m) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			y[i] += A[i][j] * x[j];
		}
	}
}

void alg2(int m) {

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < m; i++) {
			y[i] += A[i][j] * x[j];
		}
	}
}

int main() {

	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	alg2(max);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	std::cout << "Tiempo" << time_span.count() << " segundos." << endl;



	system("pause");

	return 0;
}