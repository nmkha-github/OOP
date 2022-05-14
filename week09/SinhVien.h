#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SinhVien
{
private:
	char* hoTen;
	char* maSo;
	char* ngSinh;
public:
	SinhVien();
	SinhVien(char* hoten, char* mssv, char* ngSinh);
	~SinhVien();

	SinhVien(SinhVien* a);
	SinhVien* operator=(SinhVien* a);
	void nhap();
	void xuat();
};

