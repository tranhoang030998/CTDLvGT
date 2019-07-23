#pragma once
#include "DangKy.h"
#include <cstddef>
#include "Global.h"
//Lop tin chi



struct LopTinChi {
	int MALOPTC;
	char MAMH[11];
	int NienKhoa;
	int HocKy;
	int Nhom;
	int SvMax;
	int SvMin;
	
	struct ListDangKy* listSV = NULL;
};
struct ListLopTinChi {
	int SoLuong = 0;
	LopTinChi* ds[DSDKMAX];
};

void LTC_Initial();
void Nhap(LopTinChi &ltc);
void Xuat(LopTinChi ltc);

void LTC_Nhap(ListLopTinChi &lltc);
void LTC_Xuat(ListLopTinChi lltc);

void LTC_Them(ListLopTinChi &lltc);