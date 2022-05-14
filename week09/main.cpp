#include "SinhVien.h"
#include "QuanLySinhVien.h"
int main() {
	SinhVien a;
	a.xuat();
	QuanLySinhVien ql;
	ql.themSV(&a);
	return 0;
}