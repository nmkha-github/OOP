#include "Loan.h"

Loan::Loan(long long shortLoan, long long longLoan, double rate)
{
	this->shortLoan = shortLoan;
	this->longLoan = longLoan;
	this->rate = rate;
}

void Loan::changeRate(double val)
{
	rate = val;
}

double Loan::getRate()
{
	return rate;
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
	out << "Tien no 3 nam: " << p.longLoan << " VND\n";
	out << "Lai suat no: " << p.rate * 100 << "%/thang\n";
	return out;
}
