#include "Loan.h"

Loan::Loan(long long shortLoan, double rate, long long longLoan)
{
	this->shortLoan = shortLoan;
	this->longLoan = longLoan;
	this->rate1 = rate;
	this->rate2 = 0.06;
}

void Loan::changeRate1(double val)
{
	rate1 = val;
}

void Loan::changeRate2(double val)
{
	rate2 = val;
}

double Loan::getRate1()
{
	return rate1;
}
double Loan::getRate2()
{
	return rate2;
}
long long Loan::getShortLoan()
{
	return shortLoan;
}

long long Loan::getLongLoan()
{
	return longLoan;
}

char* Loan::getDatePaying(char* type)
{
	if (type == "short")
		return (char*) "Thang 11 nam 2023";
	return (char*)"Thang 5 nam 2025";
}


std::ostream& operator<<(std::ostream& out, const Loan& p)
{
	out << "Tien no 1 nam ruoi: " << p.shortLoan << " VND\n";
	out << "Thoi diem tra: 12/2023\n";
	out << "Lai suat no: " << p.rate1 * 100 << "%/thang\n";
	out << "Tien no 3 nam: " << p.longLoan << " VND\n";
	out << "Thoi diem tra: 05/2025\n";
	out << "Lai suat no: " << p.rate2 * 100 << "%/thang\n";
	return out;
}

std::istream& operator>>(std::istream& in, Loan& p)
{
	std::cout << "Nhap tien no 1 nam ruoi (VND): "; in >> p.shortLoan;
	std::cout << "Nhap lai suat 1 nam ruoi (%/thang): "; in >> p.rate1;
	p.rate1 /= 100;
	std::cout << "Nhap tien no 3 nam (VND): "; in >> p.longLoan;
	return in;
}
