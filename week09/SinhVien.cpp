#include "SinhVien.h"

SinhVien::SinhVien() {
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

	delete this->hoTen;
	delete this->maSo;
	delete this->ngSinh;
}

SinhVien::SinhVien(SinhVien* a) {
	strcpy(this->hoTen, a->hoTen);
	strcpy(this->maSo, a->maSo);
	strcpy(this->ngSinh, a->ngSinh);
}

SinhVien* SinhVien::operator=(SinhVien* a) {
	strcpy(this->hoTen, a->hoTen);
	strcpy(this->maSo, a->maSo);
	strcpy(this->ngSinh, a->ngSinh);
	return this;
}

void SinhVien::nhap() {
	char ten[50];
	cout << "Ho ten: ";
	cin.getline(ten, 49);
	this->hoTen = new char[strlen(ten)];

	char ms[10];
	cout << "Ma so: ";
	cin.getline(ms, 9);
	this->maSo = new char[strlen(ms)];

	char ngsinh[20];
	cout << "Ngay sinh: ";
	cin.getline(ngsinh, 19);
	this->ngSinh = new char[strlen(ngsinh)];
}

void xuatChuoi(char* a) {
	for (int i = 0; i < strlen(a); i++) {
		cout << a[i];
	}
}

void SinhVien::xuat() {
	cout << "Ho ten: ";
	xuatChuoi(this->hoTen);
	cout << "\nMa so: ";
	xuatChuoi(this->maSo);
	cout << "\nNgay sinh: ";
	xuatChuoi(this->ngSinh);
}