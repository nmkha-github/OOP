#include "Bai1.h"
int main() {
    cout << "So hinh chu nhat ban dau: " << Rectangle::getCount() << endl;
    cout << endl;
    cout << "Khoi tao hinh chu nhat canh 4x3:\n";
    Rectangle a(4, 3);
    cout << "- Print method: ";
    a.print();
    cout << "- Ostream: ";
    cout << a << endl;
    cout << "So hinh chu nhat da tao ra: " << Rectangle::getCount() << endl;
    cout << endl;
    Rectangle b;
    cout << "Nhap chieu dai chieu rong (istream): ";
    cin >> b;
    cout << "Kich thuoc hinh chu nhat (ostream): ";
    cout << b << endl;
    cout << "Print method: ";
    b.print();
    cout << "So hinh chu nhat da tao ra: " << Rectangle::getCount() << endl;
}
