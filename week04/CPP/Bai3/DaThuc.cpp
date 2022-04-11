#include "DaThuc.h"

DaThuc::DaThuc() {
	pHead = NULL;
	pTail = NULL;
}

void DaThuc::NhapDaThuc() {
	int exit = 0;
	do {
		double h;
		int m;
		cout << "Nhap he so don thuc: ";
		cin >> h;
		cout << "Nhap mu so don thuc: ";
		cin >> m;

		DonThuc* p = new DonThuc(h,m);

		if (pHead == NULL) {
			pHead = p;
			pTail = p;
		}
		else if (pHead->DonThucKeTiep() == NULL) {
			pHead->DonThucKeTiep() = p;
			pTail = p;
		}
		else 
		{
			pTail->DonThucKeTiep() = p;
			pTail = p;
		}
		cout << "0. Tiep tuc nhap. \n1. Thoat. \n";
		cin >> exit;
	} while (exit == 0);
}

void DaThuc::XuatDaThuc() {
	if (pHead != NULL) {
		cout << pHead->LayHeSo() << "x^" << pHead->LaySoMu();
		DonThuc* p = pHead->DonThucKeTiep();
		while (p) {
			if (p->LayHeSo() > 0)
				cout << " + " << p->LayHeSo() << "x^" << p->LaySoMu();
			else {
				cout << " - " << -p->LayHeSo() << "x^" << p->LaySoMu();
			}
			p = p->DonThucKeTiep();
		}
		cout << endl;
	}
}

double DaThuc::TinhGiaTri(double x) {
	double sum = 0;
	DonThuc* p = pHead;
	while (p) {
		sum += p->TinhGiaTri(x);
		p = p->DonThucKeTiep();
	}
	return sum;
}

DaThuc& DaThuc::operator+(DonThuc x) {
	DonThuc* p = new DonThuc(x.LayHeSo(), x.LaySoMu());
	pTail->DonThucKeTiep() = p;
	pTail = p;
	return *this;
}

DaThuc& DaThuc::operator-(DonThuc x) {
	DonThuc* p = new DonThuc(-x.LayHeSo(), x.LaySoMu());
	pTail->DonThucKeTiep() = p;
	pTail = p;
	return *this;
}

DaThuc& DaThuc::operator*(DonThuc x) {
	DonThuc* q = new DonThuc(x.LayHeSo(), x.LaySoMu());
	DonThuc* p = pHead;
	while(p) {
		p->GanHeSo(p->LayHeSo() * q->LayHeSo());
		p->GanSoMu(p->LaySoMu() + q->LaySoMu());
		p = p->DonThucKeTiep();
	}
	return *this;
}

DaThuc& DaThuc::operator/(DonThuc x) {
	DonThuc* q = new DonThuc(x.LayHeSo(), x.LaySoMu());
	DonThuc* p = pHead;
	while (p) {
		p->GanHeSo(p->LayHeSo() / q->LayHeSo());
		p->GanSoMu(p->LaySoMu() - q->LaySoMu());
		p = p->DonThucKeTiep();
	}
	return *this;
}

DaThuc::~DaThuc() {
	while (pHead) {
		DonThuc* p = pHead->DonThucKeTiep();
		delete pHead;
		pHead = p;
	}
	pHead = NULL;
	pTail = NULL;
}