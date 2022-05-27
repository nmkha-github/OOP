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

bool BankBook::isDeadline(date time) {
	int num = (deadline.year - startDay.year) * 12 + (deadline.month - startDay.month);
	if (num < 0) {
		return false;
	}
	else
		return true;
}

long long BankBook::getProfit(date time)
{
	if (isDeadline(time) == false)
		return 0;
	else
		return moneySaving * (1 + rate);
}

std::ostream& operator<<(std::ostream& out, const BankBook& p)
{
	out << "So tien tiet kiem: " << p.moneySaving << " (VND)\n";
	out << "Ngay gui: " << p.startDay.month << '/' << p.startDay.year << '\n';
	out << "Ngay dao han: " << p.deadline.month << '/' << p.deadline.year << '\n';
	out << "Lai suat: " << p.rate * 100 << "%/thang\n";
	return out;
}

