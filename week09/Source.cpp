#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class SinhVien
{
public:
	char* hoTen;
	char* maSo;
	char* ngSinh;
	double Marks[3];

	SinhVien();
	SinhVien(char* hoten, char* mssv, char* ngSinh, double bt, double gk, double ck);
	~SinhVien();

	SinhVien(SinhVien& a);
	void operator=(SinhVien& a);
	void xuat();
	void nhap();
	double tinhDiem();
};

SinhVien::SinhVien() {
	this->hoTen = NULL;
	this->maSo = NULL;
	this->ngSinh = NULL;
	Marks[0] = 0;
	Marks[1] = 0;
	Marks[2] = 0;
}

SinhVien::SinhVien(char* hoten, char* mssv, char* ngSinh, double bt, double gk, double ck) {
	this->hoTen = new char[strlen(hoten)];
	strcpy(this->hoTen, hoten);
	this->maSo = new char[strlen(mssv)];
	strcpy(this->maSo, mssv);
	this->ngSinh = new char[strlen(ngSinh)];
	strcpy(this->ngSinh, ngSinh);
	Marks[0] = bt;
	Marks[1] = gk;
	Marks[2] = ck;
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

void SinhVien::operator=(SinhVien& a) {
	hoTen = new char[strlen(a.hoTen)];
	maSo = new char[strlen(a.maSo)];
	ngSinh = new char[strlen(a.ngSinh)];
	strcpy(hoTen, a.hoTen);
	strcpy(maSo, a.maSo);
	strcpy(ngSinh, a.ngSinh);
	Marks[0] = a.Marks[0];
	Marks[1] = a.Marks[1];
	Marks[2] = a.Marks[2];
}

void xuatChuoi(char* a) {
	if (a != NULL) {
		for (int i = 0; i < strlen(a); i++) {
			cout << a[i];
		}
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
	cout << "\nHo ten: ";
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

class QuanLySinhVien :public SinhVien
{
private:
	SinhVien* dssv;
	int size;
public:
	QuanLySinhVien();
	~QuanLySinhVien();
	void themSV(const SinhVien& a);
	void xoaSV(char* mssv);
	void xuatDS();
	void ghiDS(char* fileName);
	void docDS(char* fileName);
};

QuanLySinhVien::QuanLySinhVien() {
	size = 0;
	this->dssv = NULL;
}

QuanLySinhVien::~QuanLySinhVien() {
	delete[] dssv;
}

void QuanLySinhVien::themSV(const SinhVien& a) {
	if (dssv == NULL) {
		size = 1;
		dssv = new SinhVien[size];
		dssv[0].hoTen = new char[strlen(a.hoTen)];
		strcpy(dssv[0].hoTen, a.hoTen);
		dssv[0].maSo = new char[strlen(a.maSo)];
		strcpy(dssv[0].maSo, a.maSo);
		dssv[0].ngSinh = new char[strlen(a.ngSinh)];
		strcpy(dssv[0].ngSinh, a.ngSinh);
		dssv[0].Marks[0] = a.Marks[0];
		dssv[0].Marks[1] = a.Marks[1];
		dssv[0].Marks[2] = a.Marks[2];
	}
	else {
		SinhVien* ds = new SinhVien[size + 1];
		for (int i = 0; i < size; i++) {
			ds[i] = dssv[i];
		}
		delete[] dssv;

		size++;
		this->dssv = new SinhVien[size];
		for (int i = 0; i < size - 1; i++) {
			dssv[i] = ds[i];
		}
		dssv[size - 1].hoTen = new char[strlen(a.hoTen)];
		strcpy(dssv[size - 1].hoTen, a.hoTen);
		dssv[size - 1].maSo = new char[strlen(a.maSo)];
		strcpy(dssv[size - 1].maSo, a.maSo);
		dssv[size - 1].ngSinh = new char[strlen(a.ngSinh)];
		strcpy(dssv[size - 1].ngSinh, a.ngSinh);
		dssv[size - 1].Marks[0] = a.Marks[0];
		dssv[size - 1].Marks[1] = a.Marks[1];
		dssv[size - 1].Marks[2] = a.Marks[2];
		delete[] ds;
	}
}

void QuanLySinhVien::xoaSV(char* mssv) {
	if (dssv != NULL) {
		int flag = 0;
		int i = 0;
		for (i; i < size; i++) {
			if (strcmp(mssv, dssv[i].maSo) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "Khong tim thay SV\n";
		}
		else {
			size--;
			SinhVien* ds = new SinhVien[size];
			int j = 0;
			while (j < size) {
				if (j == i)
					continue;
				else {
					ds[j] = dssv[j];
				}
			}
			delete[] dssv;
			dssv = new SinhVien[size];
			for (int k = 0; k < size; k++) {
				dssv[k] = ds[k];
			}
			delete[] ds;
			cout << "Da xoa thong tin SV\n";
		}
	}
}

void QuanLySinhVien::xuatDS() {
	cout << "=============== DANH SACH SINH VIEN ===============\n";
	for (int i = 0; i < size; i++) {
		dssv[i].xuat();
	}
}

void QuanLySinhVien::ghiDS(char* fileName)
{
	ofstream f;
	f.open(fileName);
	f << size << endl;
	for (int i = 0; i < size; i++) {
		f << dssv[i].hoTen << endl
			<< dssv[i].maSo << endl
			<< dssv[i].ngSinh << endl
			<< dssv[i].Marks[0] << ' '
			<< dssv[i].Marks[1] << ' '
			<< dssv[i].Marks[2] << endl;
	}
	f.close();
}

void QuanLySinhVien::docDS(char* fileName)
{
	ifstream f;
	f.open(fileName);
	f >> size;
	dssv = new SinhVien[size];
	for (int i = 0; i < size; i++) {
		f.getline(dssv[i].hoTen, 50);
		f.getline(dssv[i].maSo, 50);
		f.getline(dssv[i].ngSinh, 50);
		f >> dssv[i].Marks[0];
		f >> dssv[i].Marks[1];
		f >> dssv[i].Marks[2];
	}
	f.close();
}

int main() {
	cout << "Input: tu ban phim\n";
	SinhVien a;
	a.nhap();
	a.xuat();
	SinhVien b((char*)"Pham Hong Anh", (char*)"20120252", (char*)"05/04/2002", 6, 7, 8);
	QuanLySinhVien ds;
	ds.themSV(a);
	ds.themSV(b);
	ds.xuatDS();

	/*cout << "\nInput: tu file\n";
	char* mssv = (char*)"20120502";
	ds.docDS((char*)"input.txt");
	ds.xuatDS();
	ds.ghiDS((char*)"output.txt");*/

	return 0;
}