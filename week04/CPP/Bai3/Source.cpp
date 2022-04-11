#include <iostream>
#include "DaThuc.h"
using namespace std;

int main() {
	cout << " ========== DA THUC ============\n";
	DaThuc y;
	y.NhapDaThuc();
	y.XuatDaThuc();
	cout << "\nTinh gia tri da thuc f(x) voi x = ";
	double x;
	cin >> x;
	cout << "f(" << x << ")= " << y.TinhGiaTri(x) << endl;

	cout << "Phep cong da thuc y voi don thuc k(x) = x^2\n";
	DonThuc k(1, 2);
	y = y + k;
	y.XuatDaThuc();
	cout << "Phep tru da thuc y voi don thuc l(x) = 5x^4\n";
	DonThuc l(5, 4);
	y = y - l;
	y.XuatDaThuc();
	cout << "Phep nhan da thuc y voi don thuc m(x) = 2x^2\n";
	DonThuc m(2, 2);
	y = y * m;
	y.XuatDaThuc();
	cout << "Phep chia da thuc y voi don thuc n(x) = x\n";
	DonThuc n(1, 1);
	y = y / n;
	y.XuatDaThuc();
	return 1;
}