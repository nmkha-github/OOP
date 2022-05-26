#include "Income.h"

Income::Income(long long wife, long long husband, long long couple, long long other) {
	this->wifeSalary = wife;
	this->husbandSalary = husband;
	this->coupleSalary = couple;
	this->otherSalary = other;
}

void Income::setWifeSalary(long long a) {
	this->wifeSalary = a;
}

void Income::setHusbandSalary(long long a) {
	this->husbandSalary = a;
}

void Income::setCoupleSalary(long long a) {
	this->coupleSalary = a;
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
	return this->husbandSalary + this->wifeSalary + this->coupleSalary + this->otherSalary;
}

friend std::ostream& operator<<(std::ostream& out, const Income& p);