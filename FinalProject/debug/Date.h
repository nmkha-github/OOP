#pragma once
#ifndef Date_h
#define Date_h
#include <iostream>
class Date {
public:
	int month, year;
	Date();
	Date(int month, int year);
	int operator-(const Date& p);
	Date operator=(const Date& p);
	Date input();
	void output();
	friend std::ostream& operator<<(std::ostream& out, Date& p);
};
#endif // !1
