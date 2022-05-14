#include "SinhVien.h"

SinhVien::SinhVien() {
	this->hoTen = NULL;
	this->maSo = NULL;
	this->ngSinh = NULL;
	Marks[0] = 0;
	Marks[1] = 0;
	Marks[2] = 0;
}

SinhVien::SinhVien(char* hoten, char* mssv, char* ngSinh) {
	this->hoTen = new char[strlen(hoten)];
	strcpy(this->hoTen, hoten);
	this->maSo = new char[strlen(mssv)];
	strcpy(this->maSo, mssv);
	this->ngSinh = new char[strlen(ngSinh)];
	strcpy(this->ngSinh, ngSinh);
}

SinhVien::~SinhVien() {
	this->hoTen = NULL;
	this->maSo = NULL;
	this->ngSinh = NULL;
}

SinhVien::SinhVien(SinhVien& a) {
	this->hoTen = new char[strlen(a.hoTen)];
	strcpy(this->hoTen, a.hoTen);
	this->maSo = new char[strlen(a.maSo)];
	strcpy(this->maSo, a.maSo);
	this->ngSinh = new char[strlen(a.ngSinh)];
	strcpy(this->ngSinh, a.ngSinh);
	this->Marks[0] = a.Marks[0];
	this->Marks[1] = a.Marks[1];
	this->Marks[2] = a.Marks[2];
}

SinhVien& SinhVien::operator=(SinhVien& a) {
	SinhVien b;
	b.hoTen = new char[strlen(a.hoTen)];
	b.maSo = new char[strlen(a.maSo)];
	b.ngSinh = new char[strlen(a.ngSinh)];
	strcpy(b.hoTen, a.hoTen);
	strcpy(b.maSo, a.maSo);
	strcpy(b.ngSinh, a.ngSinh);
	b.Marks[0] = a.Marks[0];
	b.Marks[1] = a.Marks[1];
	b.Marks[2] = a.Marks[2];
	return b;
}

void xuatChuoi(char* a) {
	for (int i = 0; i < strlen(a); i++) {
		cout << a[i];
	}
}

void SinhVien::nhap() {
	char ten[50];
	cout << "Ho ten: ";
	cin.getline(ten, 49);
	this->hoTen = new char[strlen(ten)];
	strcpy(this->hoTen, ten);

	char ms[10];
	cout << "Ma so: ";
	cin.getline(ms, 9);
	this->maSo = new char[strlen(ms)];
	strcpy(this->maSo, ms);

	char ngsinh[20];
	cout << "Ngay sinh: ";
	cin.getline(ngsinh, 19);
	this->ngSinh = new char[strlen(ngsinh)];
	strcpy(this->ngSinh, ngsinh);

	cout << "Diem BT = ";
	cin >> Marks[0];
	cout << "Diem GK = ";
	cin >> Marks[1];
	cout << "Diem CK = ";
	cin >> Marks[2];
}

void SinhVien::xuat() {
	cout << "Ho ten: ";
	xuatChuoi(this->hoTen);
	cout << "\nMa so: ";
	xuatChuoi(this->maSo);
	cout << "\nNgay sinh: ";
	xuatChuoi(this->ngSinh);
	cout << "\nAvg = " << tinhDiem() << endl;
}

double SinhVien::tinhDiem() {
	return Marks[0] * 0.25 + Marks[1] * 0.25 + Marks[2] * 0.5;
}