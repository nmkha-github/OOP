#include "QuanLySinhVien.h"

QuanLySinhVien::QuanLySinhVien() {
	size = 0;
	this->dssv = NULL;
}

QuanLySinhVien::~QuanLySinhVien() {
	delete[] dssv;
}

void QuanLySinhVien::themSV(SinhVien* a) {
	if (dssv == NULL) {
		size = 1;
		dssv = new SinhVien[size];
		dssv[0] = a;
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
		dssv[size - 1] = a;
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