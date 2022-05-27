#pragma once
#ifndef Loan_h
#define Loan_h
#include <iostream>
class Loan {
private:
	long long shortLoan;
	long long longLoan;
	double rate1;
	double rate2;
public:
	Loan(long long shortLoan, long long longLoan, double rate);
	void changeRate1(double val);
	void changeRate2(double val);
	double getRate1();
	double getRate2();
	long long getShortLoan();
	long long getLongLoan();
	char* getDatePaying(char* type);
	friend std::ostream& operator<<(std::ostream& out, const Loan& p);
};
#endif // !Loan_h
