#include "Income.h"

Income::Income()
{
	this->wifeSalary = 0;
	this->husbandSalary = 0;
	this->otherSalary = 0;
}

Income::Income(long long wife, long long husband, long long other)
{
	this->wifeSalary = wife;
	this->husbandSalary = husband;
	this->otherSalary = other;
}

void Income::setWifeSalary(long long a)
{
	wifeSalary = a;
}

void Income::setHusbandSalary(long long a)
{
	husbandSalary = a;
}

void Income::setOtherIncome(long long a)
{
	otherSalary = a;
}

long long Income::getWifeSalary()
{
	return wifeSalary;
}

long long Income::getHusbandSalary()
{
	return husbandSalary;
}
long long Income::getOtherIncome()
{
	return otherSalary;
}

long long Income::sumIncome()
{
	return wifeSalary + husbandSalary + otherSalary;
}
std::istream& operator>>(std::istream& in, Income& p) {
	std::cout << "Nhap luong vo: "; 
	in >> p.wifeSalary;
	std::cout << "Nhap luong chong: ";
	in >> p.husbandSalary;
	std::cout << "Nhap thu nhap khac: ";
	in >> p.otherSalary;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Income& p)
{
	out << "Luong vo: " << p.wifeSalary << " VND\n";
	out << "Luong chong: " << p.husbandSalary << " VND\n";
	out << "Thu nhap khac cua hai vo chong: " << p.otherSalary << " VND\n";
	return out;
}
