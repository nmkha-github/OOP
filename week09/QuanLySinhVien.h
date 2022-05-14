#pragma once
#include "SinhVien.h"

class QuanLySinhVien:public SinhVien
{
private:
	SinhVien* dssv;
	int size;
public:
	QuanLySinhVien();
	~QuanLySinhVien();
	void themSV(const SinhVien& a);
	void xoaSV(char* mssv);
	void ghiDS(char* fileName);
	void docDS(char* fileName);
};

