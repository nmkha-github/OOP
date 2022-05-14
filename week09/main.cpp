#include "SinhVien.h"
#include "QuanLySinhVien.h"
int main() {
	SinhVien a;
	a.nhap();
	a.xuat();
	QuanLySinhVien ds;
	ds.themSV(a);
	char* mssv = (char*) "20120502";
	ds.docDS((char*)"output.txt");
	ds.xuat();
	return 0;
}