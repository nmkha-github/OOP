#include "DonThuc.h"

DonThuc::DonThuc() {
	HeSo = 1;
	SoMu = 1;
	pNext = NULL;
}

DonThuc::DonThuc(double h, int m) {
	HeSo = h;
	SoMu = m;
	pNext = NULL;
}

void DonThuc::NhapDonThuc() {
	cout << "Nhap he so: ";
	cin >> HeSo;
	cout << "Nhap mu so: ";
	cin >> SoMu;
	pNext = NULL;
}

void DonThuc::XuatDonThuc()
{
	if(HeSo > 0)
		cout << " + " << HeSo << "x^" << SoMu;
	else {
		cout << " - " << -HeSo << "x^" << SoMu;
	}
}

DonThuc*& DonThuc::DonThucKeTiep() {
	return pNext;
}

double DonThuc::LayHeSo()
{
	return HeSo;
}

int DonThuc::LaySoMu() {
	return SoMu;
}

void DonThuc::GanHeSo(int h) {
	HeSo = h;
}

void DonThuc::GanSoMu(int m) {
	SoMu = m;
}

double DonThuc::TinhGiaTri(double x) {
	return HeSo * pow(x, SoMu);
}

DonThuc::~DonThuc() {
	pNext = NULL;
	HeSo = 0;
	SoMu = 0;
}