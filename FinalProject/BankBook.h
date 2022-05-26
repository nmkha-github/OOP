#pragma once
#ifndef BankBook_h
#define BankBook_h
#include <iostream>
class BankBook {
private:
	struct date {
		int month, year;
	};
	long long moneySaving;
	date deadline;
	double rate;
public: 
	BankBook(long long moneySaving, int month, int year, double rate);
	friend std::ostream& operator<<(std::ostream& out, const BankBook& p);
};
#endif // !BankBook_h
