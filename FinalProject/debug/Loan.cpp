#include "Loan.h"

Loan::Loan(long long shortLoan, long long longLoan, double rate)
{
	this->shortLoan = shortLoan;
	this->longLoan = longLoan;
	this->rate1 = rate;
	this->rate2 = rate;
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
	return 0;
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
	out << "Thoi diem tra: 11/2023\n";
	out << "Lai suat no: " << p.rate1 * 100 << "%/thang\n";
	out << "Tien no 3 nam: " << p.longLoan << " VND\n";
	out << "Thoi diem tra: 05/2025\n";
	out << "Lai suat no: " << p.rate2 * 100 << "%/thang\n";
	return out;
}
