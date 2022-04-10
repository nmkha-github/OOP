#pragma once
#include "Bai1.h"

Rectangle::Rectangle(double width, double height){
    this->length = width;
    this->height = height;
    count++;
}
Rectangle::Rectangle(){
    this->length = 0;
    this->height = 0;
    count++;
}
Rectangle::~Rectangle(){
    count--;
}
Rectangle::Rectangle(const Rectangle& rect){
    this->height = rect.height;
    this->length = rect.length;
    count++;
}
int Rectangle::getCount(){
    return count;
}
void Rectangle::print(){
    cout << "Chieu dai: " << length << ", chieu cao: " << height << endl;
}
ostream& operator<<(ostream& out, const Rectangle& rec){
    out << '(' << rec.length << ',' << rec.height << ')';
    return out;
}
istream& operator>>(istream& in, const Rectangle& rec){
    double length, height;
    in >> length >> height;
    return in;
}
