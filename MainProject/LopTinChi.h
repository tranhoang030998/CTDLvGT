#pragma once
#include "Mylib.h"
#include <fstream>
#include <iostream> 
#include <cstring> 
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

bool IsFull(ListLopTinChi lltc);

void Nhap_LLTC(ListLopTinChi &lltc);
void Xuat_LLTC(ListLopTinChi lltc);

void Them_LLTC(ListLopTinChi &lltc);
void Xoa_LLTC(ListLopTinChi &lltc);
void Sua_LLTC(ListLopTinChi &lltc);

void LuuFile_LLTC(ListLopTinChi lltc);
void DocFile_LLTC(ListLopTinChi &lltc);