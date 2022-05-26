#include "BankBook.h"

BankBook::BankBook(long long moneySaving, int month, int year, double rate)
{
	this->moneySaving = moneySaving;
	this->deadline.month = month;
	this->deadline.year = year;
	this->rate = rate;
}

std::ostream& operator<<(std::ostream& out, const BankBook& p)
{
	// TODO: insert return statement here
}
