#include "BankBook.h"

BankBook::BankBook(long long moneySaving, date startDay, date deadline, double rate)
{
	this->moneySaving = (moneySaving > 0) ? moneySaving: 0;
	this->startDay = startDay;
	this->deadline = deadline;
	this->rate = rate;
}

BankBook::BankBook()
{
	this->moneySaving = 0;
	this->startDay.month = 0;
	this->startDay.year = 0;
	this->deadline.month = 0;
	this->deadline.year = 0;
	this->rate = 0;
}

void BankBook::addMoney(long long val)
{
	if (val > 0)
		moneySaving += val;
}

void BankBook::setStartDay(date day)
{
	startDay = day;
}

void BankBook::setDeadline(date day)
{
	deadline = day;
}

void BankBook::setRate(double val)
{
	rate = val;
}

long long BankBook::getProfit(date time)
{
	if (time.year < startDay.year || (time.year == startDay.year && time.month < startDay.month))
		return 0;
	if (time.year > deadline.year || (time.year == deadline.year && time.month > deadline.month))
		return pow(1 + rate, deadline.year * 12 + deadline.month - startDay.year * 12 - startDay.month) * moneySaving;
	return pow(1 + rate, time.year * 12 + time.month - startDay.year * 12 - startDay.month) * moneySaving;
}

std::ostream& operator<<(std::ostream& out, const BankBook& p)
{
	out << "So tien tiet kiem: " << p.moneySaving << " (VND)\n";
	out << "Ngay gui: " << p.startDay.month << '/' << p.startDay.year << '\n';
	out << "Ngay dao han: " << p.deadline.month << '/' << p.deadline.year << '\n';
	out << "Lai suat: " << p.rate * 100 << "%/thang\n";
	return out;
}

