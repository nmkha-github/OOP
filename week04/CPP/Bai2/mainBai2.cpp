#include "HeaderBai2.h"
int main()
{
	Complex a;
	Complex b;
	cout << "Nhap so thu 1: " << endl;
	cin >> a;
	cout << "Nhap so thu 2: " << endl;
	cin >> b;
	Complex cong, tru, nhan, chia;
	cong = a + b;
	tru = a - b;
	nhan = a * b;
	chia = a / b;
	cout << "a + b= " << cong << endl;
	cout << "a - b= " << tru << endl;
	cout << "a * b= " << nhan << endl;
	cout << "a / b= " << chia << endl;
	return 0;
}
	
