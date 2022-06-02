#pragma once
#ifndef BankBook_h
#define BankBook_h
#include <iostream>
#include "Date.h"
#include <cmath>
class BankBook {
private:
	long long moneySaving;
	Date deadline;
	Date startDay;
	double rate;
public: 
	BankBook(long long moneySaving, Date startDay, Date deadline, double rate);
	BankBook();
	void addMoney(long long val);
	void setStartDay(Date day);
	void setDeadline(Date day);
	void setRate(double val);
	long long getMoneySaving();
	double getRate();
	Date getStartDay();
	Date getDeadline();
	long long getProfit(Date time);
	friend std::ostream& operator<<(std::ostream& out, const BankBook& p);
};
#endif // !BankBook_h
