#ifndef income_h
#define income_h
class Income{
private:
    long long wifeSalary;
    long long husbandSalary;
    long long coupleSalary;
    long long otherSalary;
public:
    Income(long long wife, long long husband, long long couple, long long other);
    void setWifeSalary(long long a);
    void setHusbandSalary(long long a);
    void setCoupleSalary(long long a);
    void setOtherSalary(long long a);
    long long getWifeSalary();
    long long getHusbandSalary();
    long long getCoupleSalary();
    long long getOtherSalary();
    long long sumIncome();
}
#endif