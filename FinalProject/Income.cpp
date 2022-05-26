#include "Income.h"

Income::Income(long long wife, long long husband, long long other) {
	this->wifeSalary = wife;
	this->husbandSalary = husband;
	this->coupleSalary = this->wifeSalary + this->husbandSalary;
	this->otherSalary = other;
}

void Income::setWifeSalary(long long a) {
	this->wifeSalary = a;
	this->coupleSalary = this->wifeSalary + this->husbandSalary;
}

void Income::setHusbandSalary(long long a) {
	this->husbandSalary = a;
	this->coupleSalary = this->wifeSalary + this->husbandSalary;
}

void Income::setOtherSalary(long long a) {
	this->otherSalary = a;
}

long long Income::getWifeSalary() {
	return this->wifeSalary;
}

long long Income::getHusbandSalary() {
	return this->husbandSalary;
}

long long Income::getCoupleSalary() {
	return this->coupleSalary;
}

long long Income::getOtherSalary() {
	return this->otherSalary;
}

long long Income::sumIncome() {
	return this->husbandSalary + this->wifeSalary + this->otherSalary;
}

friend std::ostream& operator<<(std::ostream& out, const Income& p);