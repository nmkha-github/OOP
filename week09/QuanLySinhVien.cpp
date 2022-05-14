#include "QuanLySinhVien.h"
#include <fstream>
#include <cstring>
#include <string.h>
using namespace std;
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
		this->dssv = new SinhVien[size];
		SinhVien* ds = new SinhVien[size + 1];
		for (int i = 0; i < size; i++) {
			ds[i] = dssv[i];
		}
		delete[] dssv;

		size++;
		this->dssv = new SinhVien[size];
		for (int i = 0; i < size; i++) {
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
