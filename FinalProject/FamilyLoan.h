#pragma once
#ifndef FamilyLoan_h
#define FamilyLoan_h
#include "Loan.h"
class FamilyLoan : public Loan {
private:
	Loan loan1;
	Loan loan2;
public:
	void calcMonthsCanPaying();
};
#endif // !1
