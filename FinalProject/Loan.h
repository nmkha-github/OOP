#pragma once
#ifndef Loan_h
#define Loan_h
#include <iostream>
class Loan {
private:
	long long shortLoan;
	long long longLoan;
	double rate;
public:
	Loan(long long shortLoan, long long longLoan, double rate);
	void changeRate(double val);
	double getRate();
	long long getShortLoan();
	long long getLongLoan();
	char* getDatePaying(char* type);
	friend std::ostream& operator<<(std::ostream& out, const Loan& p);
};
#endif // !Loan_h
