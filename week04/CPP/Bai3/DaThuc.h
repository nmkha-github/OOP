#pragma once
#include "DonThuc.h"

class DaThuc
{
private:
	DonThuc* pHead;
	DonThuc* pTail;
public:
	DaThuc();
	void NhapDaThuc();
	void XuatDaThuc();
	double TinhGiaTri(double x);
	DaThuc& operator+(DonThuc x);
	DaThuc& operator-(DonThuc x);
	DaThuc& operator*(DonThuc x);
	DaThuc& operator/(DonThuc x);
	~DaThuc();
};