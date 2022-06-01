#ifndef payment_h
#define payment_h
#include <iostream>
class Payment {
private:
    long long housePayment;
    long long foodPayment;
    long long otherPayment;
public:
    Payment();
    Payment(long long housePayment, long long foodPayment, long long otherPayment);
    void setHousePayment(long long value);
    void setFoodPayment(long long value);
    void setOtherPayment(long long value);
    long long getHousePayment();
    long long getFoodPayment();
    long long getOtherPayment();
    long long sumPayment();
    friend std::istream& operator>>(std::istream& in, Payment& p);
    friend std::ostream& operator<<(std::ostream& out, const Payment& p);
};
#endif