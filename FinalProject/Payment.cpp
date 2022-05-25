#include "Payment.h"

Payment::Payment(long long housePayment, long long foodPayment, long long otherPayment) {
	this->housePayment = housePayment;
	this->foodPayment = foodPayment;
	this->otherPayment = otherPayment;
}

void Payment::setHousePayment(long long value) {
	this->housePayment = value;
}

void Payment::setFoodPayment(long long value) {
	this->foodPayment = value;
}

void Payment::setOtherPayment(long long value) {
	this->otherPayment = value;
}

long long Payment::getHousePayment() {
	return this->housePayment;
}

long long Payment::getFoodPayment() {
	return this->foodPayment;
}

long long Payment::getOtherPayment() {
	return this->otherPayment;
}

long long Payment::sumPayment() {
	return this->foodPayment + this->housePayment + this->otherPayment;
}

friend std::ostream& operator<<(std::ostream& out, const Payment& p);