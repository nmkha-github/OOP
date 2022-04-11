#pragma once
#include <iostream>
using namespace std;

class DonThuc
{
private:
	double HeSo;
	int SoMu;
	DonThuc* pNext;
public:
	DonThuc();
	DonThuc(double h, int m);
	DonThuc*& DonThucKeTiep();
	double LayHeSo();
	int LaySoMu();
	void NhapDonThuc();
	void XuatDonThuc();
	void GanHeSo(int h);
	void GanSoMu(int m);
	double TinhGiaTri(double x);
	~DonThuc();
};

