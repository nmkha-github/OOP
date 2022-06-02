#include "Date.h"

Date::Date()
{
	this->month = 0;
	this->year = 0;
}

Date::Date(int month, int year)
{
	this->month = month;
	this->year = year;
}

int Date::operator-(const Date& p)
{
	return this->month + this->year * 12 - p.month - p.year * 12;
}

Date Date::operator=(const Date& p)
{
	this->month = p.month;
	this->year = p.year;
	return *this;
}

Date Date::input()
{
	Date startDate(5, 2022);
	Date endDate(5, 2025);
	Date p;
	do {
		int month, year;
		std::cout << "Nhap nam (2022->2025): "; std::cin >> year;
		if (year == 2022)
			std::cout << "Nhap thang (5->12): ";
		else if (year == 2025)
			std::cout << "Nhap thang (1->5): ";
		else
			std::cout << "Nhap thang (1->12): ";
		std::cin >> month;
		p = Date(month, year);
	} while (p - startDate < 0 || endDate - p < 0);
	return p;
}

std::ostream& operator<<(std::ostream& out, Date& p)
{
	out << p.month << '/' << p.year;
	return out;
}
