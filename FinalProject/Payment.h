#ifndef payment_h
#define payment_h
class Payment{
private:
    long long housePayment;
    long long foodPayment;
    long long otherPayment;
public:
    void setHousePayment(long long value);
    void setFoodPayment(long long value);
    void setOtherPayment(long long value);
    long long getHousePayment();
    long long getFoodPayment();
    long long getOtherPayment();
    long long sumPayment();
}
#endif