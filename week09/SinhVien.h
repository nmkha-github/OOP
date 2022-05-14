#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SinhVien
{
public:
	char* hoTen;
	char* maSo;
	char* ngSinh;
	double Marks[3];

	SinhVien();
	SinhVien(char* hoten, char* mssv, char* ngSinh);
	~SinhVien();

	SinhVien(SinhVien& a);
	SinhVien& operator=(SinhVien& a);
	void xuat();
	void nhap();
	double tinhDiem();
};

