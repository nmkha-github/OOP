#include "Payment.h"

Payment::Payment(long long housePayment, long long foodPayment, long long otherPayment)
{
	this->housePayment = housePayment;
	this->foodPayment = foodPayment;
	this->otherPayment = otherPayment;
}

void Payment::setHousePayment(long long value)
{
	housePayment = value;
}

void Payment::setFoodPayment(long long value)
{
	foodPayment = value;
}

void Payment::setOtherPayment(long long value)
{
	otherPayment = value;
}

long long Payment::getHousePayment()
{
	return housePayment;
}

long long Payment::getFoodPayment()
{
	return foodPayment;
}

long long Payment::getOtherPayment()
{
	return otherPayment;
}

long long Payment::sumPayment()
{
	return housePayment + foodPayment + otherPayment;
}

std::istream& operator>>(std::istream& in, Payment& p)
{
	std::cout << "Nhap tien dien nuoc: ";
	in >> p.housePayment;
	std::cout << "Nhap tien an: ";
	in >> p.foodPayment;
	std::cout << "Nhap chi tieu khac: ";
	in >> p.otherPayment;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Payment& p)
{
	out << "Tien dien nuoc: " << p.housePayment << " VND\n";
	out << "Tien an: " << p.foodPayment << " VND\n";
	out << "Chi tieu khac: " << p.otherPayment << " VND\n";
	return out;
}
