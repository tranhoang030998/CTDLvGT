#pragma once
#include <fstream>
#include <iostream> 
#include <cstring> 
#include <cstddef>
#include "Global.h"
#include "Mylib.h"
#include "Confirm.h"
#include "Frame.h"
#include "MonHoc.h"


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

void Initial_LLTC(ListLopTinChi &lltc);

bool IsFull(ListLopTinChi lltc);

void Nhap_LLTC(ListLopTinChi &lltc, ListMonHoc lmh);
void Xuat_LLTC(ListLopTinChi lltc);

void Them_LLTC(ListLopTinChi &lltc, ListMonHoc lmh);
void Xoa_LLTC(ListLopTinChi &lltc);
void Sua_LLTC(ListLopTinChi &lltc, ListMonHoc lmh);

void LuuFile_LLTC(ListLopTinChi lltc);
void DocFile_LLTC(ListLopTinChi &lltc);