#ifndef Bai1_h
#define Bai1_h
#include <iostream>
using namespace std;
class Rectangle{
private:
    double length;
    double height;
    static int count;
public:
    Rectangle(double width, double height);
    Rectangle();
    ~Rectangle();
    Rectangle(const Rectangle& rect);
    static int getCount();
    void print();

    friend ostream& operator<<(ostream& out, const Rectangle& rec);
    friend istream& operator>>(istream& in, const Rectangle& rec);
};
int Rectangle::count = 0;
#endif
