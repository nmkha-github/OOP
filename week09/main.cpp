#include "SinhVien.h"
#include "QuanLySinhVien.h"
int main() {
	SinhVien a;
	a.nhap();
	a.xuat();
	QuanLySinhVien ds;
	ds.themSV(a);
	return 0;
}