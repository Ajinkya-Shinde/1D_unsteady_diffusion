#pragma once

class Node {
public:
	double old;
	double updated;
	double x;

	void copy() {
		this->old = this->updated;
	}

	void print() {
		std::cout << x << ' ' << this->old << ' ' << this->updated << std::endl;
	}
};