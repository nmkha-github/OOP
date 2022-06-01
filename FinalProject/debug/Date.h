#pragma once
#ifndef Date_h
#define Date_h
#include <iostream>
class Date {
private:
	int month, year;
public:
	Date();
	Date(int month, int year);
	int operator-(const Date& p);
	Date operator=(const Date& p);
	Date input();
	friend std::ostream& operator<<(std::ostream& out, Date& p);
};
#endif // !1
