#include <iostream>
#include <fstream>
#include <cmath>
#include "transport.h"

#define PI 3.1415926

Node* initialize(int);
void print_node(Node*, int);
void solve_diff(Node*, int, double, double);
void write_csv(Node*, int , char);

int main() {
	int N = 128, num_itr = 1000;
	double delta_t = 0.00001;

	Node* u = new Node[N];
	u = initialize(N);
	//write_csv(u, N, 'o');
	print_node(u, N);
	solve_diff(u, N, delta_t, num_itr);
	//print_node(u, N);
	write_csv(u, N,'u');
		
}


Node* initialize(int N) {
	Node* ptr = new Node[N];
	double step = 1 / double(N - 1);
	for (int i = 0; i < N; i++) {
		ptr[i].x = (step * i);
		ptr[i].old = sin(2 * PI * ptr[i].x);
		ptr[i].updated = 0.0;
	}
	return ptr;
}
 
void print_node(Node* u, int N) {
	for (int i = 0; i < N; i++) {
		u[i].print();
	}
}

void solve_diff(Node* u, int N, double time_step, double num_itr) {
	double step = 1 / double(N - 1);
	double k;
	k = (time_step / ( pow(step,2)));
	
	for (int j = 1; j < num_itr + 1; j++) {
		for (int i = 1; i < N - 1; i++) {
			u[i].updated = k * (u[i + 1].old - 2 * u[i].old + u[i - 1].old) + u[i].old;
		}
		for (int i = 1; i < N - 1; i++) {
			u[i].copy();
		}
		//if (num_itr % 1000 == 0) {write_csv(u)}
	}
	
}

void write_csv(Node* u, int N, char c) {
	std::fstream fout;
	fout.open("solution_1d.csv", std::ios::out | std::ios::app);

	if (c == 'o') {
		for (int i = 0; i < N; i++) {
			fout << u[i].old << ',';
		}
		fout << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			fout << u[i].updated << ',';
		}
		fout << '\n';
	}
	
}