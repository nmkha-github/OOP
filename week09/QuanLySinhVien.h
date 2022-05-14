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
	void themSV(SinhVien a);
	void xoaSV(char* mssv);
};

