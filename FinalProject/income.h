#ifndef Income_h
#define Income_h
#include <iostream>
class Income {
private:
    long long wifeSalary;
    long long husbandSalary;
    long long otherSalary;
public:
    Income(long long wife, long long husband, long long other);
    void setWifeSalary(long long a);
    void setHusbandSalary(long long a);
    void setOtherSalary(long long a);
    long long getWifeSalary();
    long long getHusbandSalary();
    long long getOtherSalary();
    long long sumIncome();
    friend std::ostream& operator<<(std::ostream& out, const Income& p);
};
#endif