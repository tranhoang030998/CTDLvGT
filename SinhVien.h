#pragma once
#include "Frame.h"
//khai bao danh sach sinh vien
#include<string>
using namespace std;
struct SinhVien {
	char MASV[13];
	char Ho[9];
	char Ten[10];
	bool Phai;
	char SDT[11];
	char MALOP[16];
	int NamNhapHoc;
};
struct NoteSV {
	SinhVien sinhvien;
	NoteSV* next;
};
typedef NoteSV* ListSinhVien;

void Nhap_SV(ListSinhVien &lsv);
void Xuat_SV(ListSinhVien lsv);


