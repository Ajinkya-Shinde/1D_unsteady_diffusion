#include <iostream>
#include <cmath>

#define PI 3.1415926

double* init_array(int);
double* init_temp(double*, int);
double* solve_diff(double*, double*, int, double, double);
void print_array(double*, int);

int main() {
	int N = 50;
	double del_t = 0.0001;
	double* x = new double[N];
	double* T= new double[N];
	x = init_array(N);
	T = init_temp(x, N);
	double* sol = new double[N];
	sol = solve_diff(x, T, N, del_t, 2);
	print_array(sol,N);
	//print_array(x, N);
	//print_array(T, N);
	delete [] x;
	delete [] T;
}

double* init_array(int N) {
	double* ptr = new double[N];
	double step = 1 / ((double)(N-1));
	for (int i{ 0 }; i < N; i++) {
		ptr[i] = step * i;
	}
	return ptr;
}

double* init_temp(double* x, int N) {
	double* ptr = new double[N];
	double step = 1 / (double)(N - 1);
	for (int i{ 0 }; i < N; i++) {
		ptr[i] = sin(2*PI*x[i]);
	}
	return ptr;
}

double* solve_diff(double* x, double* T, const int N, double time_step, double time) {
	double step = 1 / (double)(N - 1);
	double* T_up=new double[N];
	T_up[0] = T[0];
	T_up[N - 1] = T[N - 1];
	for (int j = 0; j<int(time / time_step); j++) {
		for (int i = 1; i < N-1 ; i++) {

			T_up[i] = (time_step / (2 * step)) * (T[i + 1] - 2 * T[i] + T[i - 1]) + T[i];

		}
		for (int i = 1; i < N-1; i++) {
			T[i] = T_up[i];
		}
	}
	return T_up;
}

void print_array(double* ptr, int N) {
	for (int i{ 0 }; i < N; i++) {
		std::cout << ptr[i] << ' ';
	}
	std::cout << std::endl;
}