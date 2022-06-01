#pragma once
#ifndef BankBook_h
#define BankBook_h
#include <iostream>
#include <cmath>
class BankBook {
private:
	struct date {
		int month, year;
	};
	long long moneySaving;
	date deadline;
	date startDay;
	double rate;
public: 
	BankBook(long long moneySaving, date startDay, date deadline, double rate);
	BankBook();
	void addMoney(long long val);
	void setStartDay(date day);
	void setDeadline(date day);
	void setRate(double val);
	long long getProfit(date time);
	friend std::ostream& operator<<(std::ostream& out, const BankBook& p);
};
#endif // !BankBook_h
