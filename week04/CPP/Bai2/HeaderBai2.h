#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex {
private:
	int Re, Im;

public:

	Complex();
	Complex(int r, int i);
	// Overload operator '+', '-', '*', '/'
	friend Complex operator+ (Complex const& C1, Complex const& C2);
	friend Complex operator- (Complex const& C1, Complex const& C2);
	friend Complex operator* (Complex const& C1, Complex const& C2);
	friend Complex operator/ (Complex const& C1, Complex const& C2);
	friend ostream& operator<< (ostream& out, Complex& C);
	friend istream& operator>> (istream& in, Complex& C);
	// Other functions
};
#endif
