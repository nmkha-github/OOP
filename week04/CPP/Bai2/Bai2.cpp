#include "HeaderBai2.h"
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
	ans.Im = C1.Re * C2.Im + C1.Im * C2.Re;
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
	if (C.Re == 0 && C.Im != 0)
		out << C.Im << "i";
	if (C.Im > 0)
		out << C.Re << " + " << C.Im << "i";
	else if (C.Im < 0)
		out << C.Re << " - " << -C.Im << "i";
	else if (C.Im == 0) 
		out << C.Re;

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
