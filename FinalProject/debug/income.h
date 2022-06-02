#ifndef Income_h
#define Income_h
#include <iostream>
class Income {
private:
    long long wifeSalary;
    long long husbandSalary;
    long long otherSalary;
public:
    Income();
    Income(long long wife, long long husband, long long other);
    void setWifeSalary(long long a);
    void setHusbandSalary(long long a);
    void setOtherIncome(long long a);
    long long getWifeSalary();
    long long getHusbandSalary();
    long long getOtherIncome();
    long long sumIncome();
    long long sumSalary();
    friend std::istream& operator>>(std::istream& in, Income& p);
    friend std::ostream& operator<<(std::ostream& out, const Income& p);
};
#endif