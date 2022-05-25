#include "Loan.h"

Loan::Loan(long long debt, double rate, char datePaying[]) {
	this->debt = debt;
	this->rate = rate;
	strcpy(this->datePaying, datePaying);
}

void Loan::changeRate(double val) {
	this->rate = val;
}

double Loan::getRate() {
	return this->rate;
}

long long Loan::getDebt() {
	return this->debt;
}

char* Loan::getDatePaying() {
	return this->datePaying;
}