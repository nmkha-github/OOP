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
Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(int r, int i)
{
	Re = r;
	Im = i;
}

Complex operator+ (Complex const& C1, Complex const& C2)
{
	Complex ans;
	ans.Re = C1.Re + C2.Re;
	ans.Im = C1.Im + C2.Im;
	return ans;
}

Complex operator- (Complex const& C1, Complex const& C2)
{
	Complex ans;
	ans.Re = C1.Re - C2.Re;
	ans.Im = C1.Im - C2.Im;
	return ans;
}

Complex operator* (Complex const& C1, Complex const& C2)
{
	Complex ans;
	ans.Re = C1.Re * C2.Re - C1.Im * C2.Im;
	ans.Im = C1.Re * C2.Im - C1.Im * C2.Re;
	return ans;
}

Complex operator/ (Complex const& C1, Complex const& C2)
{
	Complex ans;
	int a = C1.Re;
	int b = C1.Im;
	int c = C2.Re;
	int d = C2.Im;
	ans.Re = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
	ans.Im = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
	return ans;
}

ostream& operator<< (ostream& out, Complex& C)
{
	out << C.Re << " + " << C.Im << "i"; 

	return out;
}

istream& operator>> (istream& in, Complex& C)
{
	cout << "Nhap phan ao: ";
	in >> C.Re;
	cout << "Nhap phan thuc: ";
	in >> C.Im;

	return in;
}

int main()
{
	Complex a;
	cin >> a;
	cout << a;
	
}
#endif
