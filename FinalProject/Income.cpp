#include "Income.h"

Income::Income(long long wife, long long husband, long long couple, long long other) {
	this->wifeSalary = wife;
	this->husbandSalary = husband;
}

void Income::setWifeSalary(long long a);
void Income::setHusbandSalary(long long a);
void Income::setCoupleSalary(long long a);
void Income::setOtherSalary(long long a);
long long Income::getWifeSalary();
long long Income::getHusbandSalary();
long long Income::getCoupleSalary();
long long Income::getOtherSalary();
long long Income::sumIncome();
friend std::ostream& operator<<(std::ostream& out, const Income& p);