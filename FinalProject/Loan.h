#pragma once
#ifndef Loan_h
#define Loan_h
#include <iostream>
class Loan {
private:
	long long debt;
	char datePaying[10];
	double rate;
public:
	Loan(long long debt, double rate, char datePaying[]);
	void changeRate(double val);
	double getRate();
	long long getDebt();
	char* getDatePaying();
	
};
#endif // !Loan_h
